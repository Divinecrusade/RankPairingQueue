﻿# <h1 align="center">Rank Pairing Queue (RPQ)<br>Приоритетная очередь на взвешенной спаренной куче</h1>
---
## Краткое описание

Это приложение является реализацией в объектно-ориентированном стиле на языке C++ (стандарт 20 года) структуры данных типа приоритетная очередь, основанной на взвешенной спаренной куче (Rank Pairing Heap).
В основе лежит наполовину отсортированное двоичное дерево (Half Ordered Binary Tree).
Идея взята из статьи[^1] Rank-Pairing Heaps за авторством Bernhard Haeupler, Siddhartha Sen и Robert E. Tarjan.

Проект выполнен в IDE Microsoft Visual Studio 2022.

<i>В дальнейшем совокупность компонентов (без класса `Request` и файла `Unit1.cpp`) будет называться "модулем".</i>

## Возможности

<i>Ключ и приоритет понимаются как синонимы.</i>

Модуль предоставляет приоритетную очередь с высокой эффективностью основных операций.
Данный вид приоритетной очереди относят к min-priority queue. То есть, в начале очереди всегда находится элемент с минимальным значением ключа. 
Реализованные операции:
- вставка (insert) (S, x) – помещает элемент x в множество S;
- нахождение минимума (minimum) (S) – возвращает элемент множества S с наименьшим ключом;
- извлечение минимума (extract-min) (S) – удаляет из множества S элемент с наименьшим ключом;
- уменьшение ключа (decrease-key) (S, x, k) – устанавливает значение k для ключа элемента x из множества S.

Рассматриваемая реализация примечательна тем, что имея хорошие показатели асимптотической сложности выполнения основных функций (особенно уменьшение ключа) она отличается сравнительно простой внутренней организацией данных. 
А такие операции как изменение ключа или извлечение минимума не приводят к сложным перестроениям.

Модуль автономен и может быть использован в других проектах C++.

## Ограничения

Важно отметить, <b>модуль не управляет временем жизни подаваемых на вход приоритетных элементов</b>. Он только агрегирует их в виде ссылок. 
Таким образом, освобождение памяти должно быть произведено извне и строго после извлечения соответствующего элемента из очереди.

Это сделано с целью недопущения излишнего копирования. Возможно, в дальнейшем ссылки в полях соответствующих классов будут заменены на умные указатели.

## Подключение

Модуль состоит из следующих файлов (все файлы проекта, кроме файлов `Request.hpp`, `Request.cpp` и `Unit1.cpp`) в алфавитном порядке:
- `IPriorityElement.hpp` - объявление интерфейса для приоритетных элементов;
- `IPriorityQueue.hpp` - объявление интерфейса приоритетной очереди;
- `IRankedRootsList.hpp` - объявление интерфейса списка корней деревьев (куча);
- `IRankedTree.hpp` - объявление интерфейса взвешенного дерева;
- `MeldableRankedBinaryTree.cpp` - реализация двоичного дерева, поддерживающего объединение (слияние, meld);
- `MeldableRankedBinaryTree.hpp` - объявление двоичного дерева, поддерживающего объединение (слияние, meld);
- `RankedBinaryTree.cpp` - реализация двоичного взвешенного дерева;
- `RankedBinaryTree.hpp` - объявление двоичного взвешенного дерева;
- `RankedHalfBinaryTree.cpp` - реализация двоичного наполовину отсортированного взвешенного дерева;
- `RankedHalfBinaryTree.hpp` - объявление двоичного наполовину отсортированного взвешенного дерева;
- `RankedRootsList.cpp` - реализация списка корней деревьев (куча);
- `RankedRootsList.hpp` - объявление списка корней деревьев (куча);
- `RankPairingQueue.cpp` - реализация приоритетной очереди на взвешенной спаренной куче;
- `RankPairingQueue.hpp` - объявление приоритетной очереди на взвешенной спаренной куче;

Чтобы использовать модуль необходимо скачать все эти файлы и поместить их, например, в директорию с исходниками другого приложения.
Затем в начале файла кода, где планируется использовать данную очередь, подключить заголовочный файл `RankPairingQueue.hpp`:
```c++
#include "RankPairingQueue.hpp"
```
Для простоты обращения можно импортировать имя:
```c++
using PriorityQueue::RankPairingQueue; 
```

## Использование

<i>Файл `Unit1.cpp` представляет собой консольное приложение, демонстрирующее способ использования модуля и позволяющее в интерактивном режиме проверить корректность выполнения основных операций.</i>

После того как модуль был успешно подключен нужно создать экземпляр класса `PriorityQueue::RankPairingQueue`:
```c++
#include "RankPairingQueue.hpp"         // подключение модуля

PriorityQueue::RankPairingQueue rpq{ }; // создание очереди 
```
В нем инкапсулированы все методы приоритетной очереди. Работает он с объектами, реализущими интерфейс `PriorityQueue::Abstract::Interfaces::IPriorityElement`:
```c++
#include "RankPairingQueue.hpp"                               // подключение модуля

class Request : public Abstract::Interfaces::IPriorityElement // пример элемента с приоритетом
{
public:
    
    Request(int id, unsigned priority) : id{ id }, priority{ priority }
	{ }

    virtual ~Request() = default;

    virtual unsigned get_priority() const override
	{
		return priority;
	}
    virtual void set_priority(unsigned new_priority) override
	{
		priority = new_priority;
	}
    virtual int get_id() const override
	{
		return id;
	}

private:

    int const id;
    unsigned priority;
};


Request r0{0, 1};                       // создание элемента с идентификатором 0 и приоритетом 1
PriorityQueue::RankPairingQueue rpq{ }; // создание очереди 


// Если объект очереди пустой, но у него вызываются метод получения/извлечения минимума
// то выбрасывается исключение
try
{
    rpq.minimum();  // получение минимума
}
catch (PriorityQueue::RankPairingQueue::empty_queue const&)
{
    rpq.insert(r0);	// добавление элемента в очередь
					// очередь теперь не пуста

	rpq.minimum();					  // будет возвращена ссылка на r0
	rpq.decrease_key(r0.get_id(), 0); // понижение приоритета у r0 до 0
	rpq.extract_min();				  // извлечение минимума
									  // r0 исключен из очереди, очередь снова пуста
}
```
Следует обозначить некоторые особенности реализации:
- как уже было отмечено ранее, очередь никаким образом не влияет на время жизни передаваемых в нее элементов. Поэтому разрушение (вызов деструктора) очереди не приводит к уничтожению хранимых в ней приоритетных элементов;
- очередь позволяет хранить произвольное количество элементов с одинаковым приоритетом;
- повторная вставка в очередь элемента, равно как и вставка элементов с повторяющимися идентификаторами (то, что возвращается методом `get_id()` у наследников интерфейса `PriorityQueue::Abstract::Interfaces::IPriorityElement`) приводит к <b>неопределенному поведению</b>;
- изменение приоритета у элементов, хранящихся в очереди, без использования соответствующего метода, как и увеличение приоритета элемента через метод `decrease_key` приводит к <b>неопределенному поведению</b>.

## Структура модуля

![Схема 1. Диаграмма классов, задействованных в реализации очереди](/img/scheme1_classes.png)
<p align="center">Диаграмма классов, задействованных в реализации очереди</p>
<br>

Все компоненты, иными словами классы, распределены по пространствам имен. Всего их четыре:
1. `PriorityQueue`. Основное пространство имен. В него входят все остальные. Включает все компоненты модуля, задействованные в реализации приоритетной очереди на взвешенной спаренной куче;
2. `PriorityQueue::Abstract`. Содержит все интерфейсы (пространство имён `Interfaces`) и абстрактные классы. Таким образом, данное пространство имён объединяет классы, частично или полностью нереализованные;
3. `PriorityQueue::Abstract::Interfaces`. Включает только интерфейсы, описывающие базовое поведение всех классов программного средства;
4. `PriorityQueue::Auxiliry`. Здесь находятся вспомогательные полностью реализованные классы.

Взаимодействие между классами происходит строго с помощью ссылок и указателей на интерфейс или на абстрактный класс.
Соблюдаются различные уровни абстракции между компонентами. Таким образом, степень связанности объектов сведена к минимуму.

Финальным (выполняет все функции приоритетной очереди) и полностью автономным (все зависимости подключены в определении) классом является `RankPairingQueue`. Он инкапсулирует и абстрагирует всю логику приоритетной очереди, построенной на взвешенной спаренной куче.
С `RankPairingQueue` в отношении композиции находится объект класса `RankedRootsList`, представляющий собой список (кучу) корней взвешенных, наполовину отсортированных двоичных деревьев. Этот класс отвечает за изъятие, объединение и добавление новых деревьев.
Деревья описываются классом `RankedHalfBinaryTree`. В нем содержится логика объединения деревьев, подсчёта веса, поиска и извлечения поддеревьев.
Данные компоненты работают с классами, реализующими интерфейс `IPriorityElement`. 

## Описание структуры данных

В основе взвешенной спаренной кучи лежит так называемое "наполовину сбалансированное двоичное дерево"[^1], представляющее собой двоичную кучу, но лишь с одним левым поддеревом.
Главное свойство заключается в том, что каждый узел меньше любого из узлов в левом поддереве.

![Пример наполовину отсортированного двоичного дерева (a) и его эквивалента в виде кучи (представленной как сильноветвящееся дерево) (b)](/img/tree_example.png)
<p align="center">Пример наполовину отсортированного двоичного дерева (a) и его эквивалента в виде кучи (представленной как сильноветвящееся дерево) (b)</p>
<br>

С целью повышения эффективности работы структуры, для каждого узла вводится целочисленный «вес», или «ранг» (rank). 
Изначально он равен 0. После добавления (связывания) потомка, вес родителя, как и вес предков родителя, увеличивается на 1. 
Вес всего дерева определяется весом корня.
Правила для вычисления веса можно представить следующим образом:
- если узел – терминальная вершина, то его вес равен 0;
- если узел – корень, то его вес равен весу его левого поддерева + 1;
- если модуль разности весов левого и правого поддеревьев меньше или равен 1, то вес узла равен максимальному весу среди левого и правого поддеревьев + 1;
- если модуль разности весов левого и правого поддеревьев больше 1, то вес узла равен максимальному весу среди левого и правого поддеревьев.

Множество (список) таких деревьев образуют взвешенную спаренную кучу.
Операции над структурой:
- нахождение минимума (minimum). Корень первого дерева списка всегда является минимальным элементом. Часто он называется «минимальным корнем» (min-root);
- вставка (insert). Новый узел становится корнем нового дерева, который добавляется в список на первое место (если приоритет нового элемента меньше приоритета текущего минимального элемента) или на второе;
- извлечение минимума (extract-min). Нужно удалить корень из дерева с минимальным элементом. Сделать его левый (и единственный) потомок корнем дерева, при этом всё правое поддерево поделить на новые деревья и добавить их в список. Пересчитать веса;
- уменьшение ключа (decrease-key). Изменить ключ искомого узла. Если он – корень, и его приоритет стал меньше приоритета минимального корня, то переместить его на первую позицию в списке. Если искомый узел не корень, то заменить его на правое поддерево, а сам узел с левым поддеревом добавить в список как новое дерево.

Для достижения эффективной работы кучи в тех случаях, когда образуются новые деревья (после извлечения, изменения ключа и вставки), следует соединять деревья с одинаковым весом. Данная операция выполняется по такому алгоритму:
1. Сравнить ключи двух корней x и y;
2. Если x и y – корни с меньшим и большим ключом соответственно, то отсоединить левое поддерево x и сделать его правым поддеревом y;
3. Сделать x корнем нового дерева, где y – левое поддерево;
4. Увеличить вес x на 1.

### Оценка эффективности

<i>Здесь отождествление куч с приоритетными очередями корректно, поскольку у них один и тот же интерфейc.</i>

Для сравнения ниже приведена таблица с асимптотической сложностью операций у разных куч.

Эффективность операций приоритетной очереди, построенной на куче

| Тип кучи | insert | minimum | extract-min | decrease-key |
| -------- | ------ | ------- | ----------- | ------------ |
| двоичная[^2] | O (log<sub>2</sub>n) | Θ (1) | Θ (log<sub>2</sub>n) | O (log<sub>2</sub>n) |
| биноминальная[^3] | Θ (1) | Θ (1) | Θ (log<sub>2</sub>n) | Θ (log<sub>2</sub>n) | 
| косая биноминальная[^3] | Θ (1) | Θ (1) | Θ (log<sub>2</sub>n) | Θ (log<sub>2</sub>n) |
| спаренная[^4] | Θ (1) | Θ (1) | O (log<sub>2</sub>n) | O (log<sub>2</sub>n) | 
| **взвешенная спаренная**[^1] | **Θ (1)** | **Θ (1)** | **O (log<sub>2</sub>n)** | **Θ (1)** |
| Фибоначчиева[^3] | Θ (1) | Θ (1) | O (log<sub>2</sub>n) | Θ (1) | 
| строгая Фибоначчиева[^5] | Θ (1) | Θ (1) | O (log<sub>2</sub>n) | Θ (1) |
| куча Бродала-Окасаки[^6] | Θ (1) | Θ (1) | O (log<sub>2</sub>n) | Θ (1) |
| 2-3 куча[^7] | O (log<sub>2</sub>n) | O (log<sub>2</sub>n) | O (log<sub>2</sub>n) | Θ (1) |

Тем не менее, следует отметить, что ввиду возможности дублирования ключей (приоритетов) операция уменьшения ключа несколько теряет в эффективности. 
Это объясняется тем, что поиск происходит не только с логарифмической сложностью, но и в случае наличия элементов с одинаковыми приоритетами – по линейной зависимости от количества дубликатов.

### Экспериментальная оценка (оценка реализации)

Для экспериментальной оценки эффективности операций разработанной очереди был применён следующий подход. 
Формируется пул заявок размером 16385 единиц. При этом гарантируется, что четверть из них повторяют значение времени обслуживания других заявок. 
Затем пул делится на 15 последовательностей, содержащие соответственно 0, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384 заявок в случайном (по времени обслуживания) порядке. 
После этого в очередь вставляется первая последовательность. 

Следующий шаг – вычисление времени выполнения операций над очередью (вставка, получение минимума, уменьшение ключа и извлечение минимума). При этом проводится 100 попыток, после чего берётся среднее значение.
Очередь очищается, в неё помещается вторая последовательность, снова вычисляется время выполнения операций и так до тех пор, пока не закончатся подготовленные последовательности заявок.

Результаты сведены в таблицу ниже.

Время выполнения (в миллисекундах) основных операций над очередью в зависимости от количества заявок в очереди
<table>
	<thead>
		<tr>
			<th>Количество элементов в очереди</th>
			<th>Время выполнения вставки (insert), мс</th>
			<th>Время выполнения получения минимума (minimum), мс</th>
			<th>Время выполнения извлечения минимума (extract), мс</th>
			<th>Время выполнения уменьшения ключа (decrease key), мс</th>
		</tr>
	</thead>
	<tbody>						
		<tr>
			<td>0</td>
			<td>0,009</td>
			<td>0,0001</td>
			<td>0,0001</td>
			<td>0,005</td>
		</tr>
		<tr>
			<td>2</td>
			<td>0,036</td>
			<td>0,0001</td>
			<td>0,0001</td>
			<td>0,0001</td>
		</tr>
		<tr>
			<td>4</td>
			<td>0,033</td>
			<td>0,0001</td>
			<td>0,001</td>
			<td>0,007</td>
		</tr>
		<tr>
			<td>8</td>
			<td>0,0001</td>
			<td>0,0001</td>
			<td>0,032</td>
			<td>0,0001</td>
		</tr>
		<tr>
			<td>16</td>
			<td>0,003</td>
			<td>0,0001</td>
			<td>0,101</td>
			<td>0,002</td>
		</tr>	
		<tr>
			<td>32</td>
			<td>0,038</td>
			<td>0,0001</td>
			<td>1,141</td>
			<td>0,0001</td>
		</tr>
		<tr>
			<td>64</td>
			<td>0,0001</td>
			<td>0,0001</td>
			<td>3,019</td>
			<td>0,016</td>
		</tr>
		<tr>
			<td>128</td>
			<td>0,001</td>
			<td>0,0001</td>
			<td>5,991</td>
			<td>0,004</td>
		</tr>
		<tr>
			<td>256</td>
			<td>0,01</td>
			<td>0,0001</td>
			<td>11,771</td>
			<td>0,003</td>
		</tr>
		<tr>
			<td>512</td>
			<td>0,034</td>
			<td>0,0001</td>
			<td>21,876</td>
			<td>0,002</td>
		</tr>
		<tr>
			<td>1024</td>
			<td>0,004</td>
			<td>0,0001</td>
			<td>37,699</td>
			<td>0,001</td>
		</tr>
		<tr>
			<td>2048</td>
			<td>0,037</td>
			<td>0,0001</td>
			<td>59,869</td>
			<td>0,001</td>
		</tr>
		<tr>
			<td>4096</td>
			<td>0,082</td>
			<td>0,0001</td>
			<td>88,386</td>
			<td>0,001</td>
		</tr>
		<tr>
			<td>8192</td>
			<td>0,0001</td>
			<td>0,0001</td>
			<td>136,715</td>
			<td>0,012</td>
		</tr>				
		<tr>
			<td>16384</td>
			<td>0,074</td>
			<td>0,0001</td>
			<td>227,844</td>
			<td>0,004</td>
		</tr>
	</tbody>
</table>

Из приведенных данных следует, что время выполнения всех операций, кроме извлечения минимума, действительно не имеют ни логарифмической, ни линейной, ни тем более квадратичной зависимости от количества элементов. 
Подтверждение выводов можно видеть на графиках ниже.

![График зависимости времени выполнения операций от количества элементов в очереди](/img/chart1.png)
<p align="center">График зависимости времени выполнения операций от количества элементов в очереди</p>
<br>

![График зависимости времени выполнения операций константной сложности от количество элементов в очереди (от 0 до 200 заявок)](/img/chart2.png)
<p align="center">График зависимости времени выполнения операций константной сложности от количество элементов в очереди (от 0 до 200 заявок)</p>
<br>

![График зависимости времени выполнения операций константной сложности от количество элементов в очереди (от 0 до 17000 заявок)](/img/chart3.png)
<p align="center">График зависимости времени выполнения операций константной сложности от количество элементов в очереди (от 0 до 17000 заявок)</p>

## Схемы основных алгоритмов

![Схема выполнения операции "вставка элемента"](/img/scheme2_alg1.png)
<p align="center">Схема выполнения операции "вставка элемента"</p>
<br>

![Схема выполнения операции "извлечение минимума"](/img/scheme3_alg2.png)
<p align="center">Схема выполнения операции "извлечение минимума"</p>
<br>

![Схема выполнения операции "уменьшение ключа"](/img/scheme4_alg3.png)
<p align="center">Схема выполнения операции "уменьшение ключа"</p>
<br>

![Схема выполнения разбиения дерева на поддеревья и помещения их в кучу](/img/scheme5_alg4.png)
<p align="center">Схема выполнения разбиения дерева на поддеревья и помещения их в кучу</p>
<br>

![Схема выполнения объединения деревьев с одинаковыми весами](/img/scheme6_alg5.png)
<p align="center">Схема выполнения объединения деревьев с одинаковыми весами</p>
<br>

![Схема выполнения объединения узлов списка деревьев](/img/scheme7_alg6.png)
<p align="center">Схема выполнения объединения узлов списка деревьев</p>


[^1]: Haeupler B Rank-Pairing Heaps / B. Haeupler, S. Sen, R.E. Tarjan // Society for industrial and Applied Mathematics. – 2011. Vol. 40. № 6. – P.1463-1485
[^2]: Кормен, Т. Алгоритмы. Построение и анализ / Т. Кормен, Ч. Лейзерсон, Р. Ривест, К. Штайн. – М.: Вильямс, 2020. – 1328 с.
[^3]: Brodal G.S. Optimal Purely Functional Priority Queues / G.S. Brodal, C. Okasaki // Journal of Functional Programming. – 1996. Vol. 6. – P.839-857
[^4]: Iacono J. Improved Upper Bounds for Pairing Heaps / J. Iacono //Algorithm Theory - SWAT 2000. – 2002. – P.32-45
[^5]: Brodal G.S. Strict Fibonacci Heaps / G.S. Brodal, G. Lagogiannis, R.E. Tarjan // STOC `12: Proceedings of the forty-fourth annual ACM symposium on Theory of computing. – 2012. – P.1177-1184
[^6]: Brodal G.S. Worst-Case Efficient Priority Queues / G.S. Brodal // SODA96: Conference on Discrete Algorithms. – 1996. – P.52-58
[^7]: Takaoka T. Theory of 2-3 Heaps / T. Takaoka // Discrete Applied Mathematics. – 2003. Vol. 126. – P.115-128