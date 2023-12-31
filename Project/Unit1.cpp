#include "RankPairingQueue.hpp"
#include "Request.hpp"

#include <iostream>
#include <locale>
#include <map>
#include <unordered_map>
#include <memory>
#include <Windows.h>


namespace
{
    enum class AppActions : int
    {
        ADD_TO_QUEUE        = 1,
        SHOW_MINIMUM        = 2,
        EXTRACT_MINIMUM     = 3,
        DECREASE_KEY        = 4,
        EXIT
    };

    std::wistream& operator>>(std::wistream& in,  AppActions& k)
    {
        int d{ };

        in >> d;

        switch (d)
        {
            case 1:  k =  AppActions::ADD_TO_QUEUE;        break;
            case 2:  k =  AppActions::SHOW_MINIMUM;        break;
            case 3:  k =  AppActions::EXTRACT_MINIMUM;     break;
            case 4:  k =  AppActions::DECREASE_KEY;        break;
            default: k =  AppActions::EXIT;                break;
        }

        return in;
    }
    std::wostream& operator<<(std::wostream& out, AppActions const& k)
    {
        return (out << static_cast<int>(k));
    }

    static std::map<AppActions, wchar_t const* const> const AVAILABLE_ACTIONS
    {
        { AppActions::ADD_TO_QUEUE,        L"�������� ����� ������ � �������" },
        { AppActions::SHOW_MINIMUM,        L"�������� ������ � ����������� �������� ������������ � �������" },
        { AppActions::EXTRACT_MINIMUM,     L"������� ������ � ����������� �������� ������������ � �������" },
        { AppActions::DECREASE_KEY,        L"��������� ����� ������������ ������" }
    };
}


int wmain()
{
    static constexpr wchar_t const* const SEPARATOR{ L"-------------------------------" };
    
    std::wcout.imbue(std::locale("rus_rus.866"));


    AppActions choosen_action{ };
    std::unordered_map<int, PriorityQueue::Request> requests{ };
    std::unique_ptr<PriorityQueue::Abstract::Interfaces::IPriorityQueue> 
    requests_queue { std::make_unique<PriorityQueue::RankPairingQueue>() };


    while (true)
    {
        std::wcout << L"�������� ��������:\n";
        for (auto it{ AVAILABLE_ACTIONS.cbegin() }; it != AVAILABLE_ACTIONS.cend(); ++it)
        {
            std::wcout << it->first << L" - " << it->second << L'\n';
        }
        std::wcout << L"����� ������ ���� - ����� �� ���������\n\n";

        std::wcin >> choosen_action;

        std::wcout << std::endl;

        switch (choosen_action)
        {
            case AppActions::ADD_TO_QUEUE:
            {
                int id{ };
                unsigned int priority{ };

                std::wcout << L"������� ������������� ������:         ";
                std::wcin >> id;
                
                if (requests.find(id) != requests.end())
                {
                    std::wcout << L"�������� ��������: ������ � ����� ��������������� ��� ��������� � �������\n";

                    break;
                }

                std::wcout << L"������� ����� �� ������������ ������: ";
                std::wcin >> priority;

                requests.emplace(id, PriorityQueue::Request{ id, priority });
                requests_queue->insert(requests.at(id));
                std::wcout << L"������ ��������� � �������\n";
            }
            break;

            case AppActions::SHOW_MINIMUM:
            {
                try
                {
                    std::wcout << L"������ � ������ ������� ������ � ��������������� \n" << requests_queue->minimum().get_id()
                               << L" � �������� �� ������������ " << requests_queue->minimum().get_priority() << L'\n';
                }
                catch (PriorityQueue::RankPairingQueue::empty_queue const&)
                {
                    std::wcout << L"������� �����\n";
                }
            }
            break;

            case AppActions::EXTRACT_MINIMUM:
            {
                try
                {
                    auto const& deleted_detail{ requests_queue->minimum() };
                    requests_queue->extract_min();
                    requests.erase(deleted_detail.get_id());

                    std::wcout << L"������ ��������� �� �������\n";
                }
                catch (PriorityQueue::RankPairingQueue::empty_queue const&)
                {
                    std::wcout << L"�������� ��������: ������� �����\n";
                }
            }
            break;

            case AppActions::DECREASE_KEY:
            {
                int id{ };

                std::wcout << L"������� ������������� ������:                ";
                std::wcin >> id;

                if (requests.find(id) == requests.end())
                {
                    std::wcout << L"�������� ��������: ������ � ����� ��������������� �� ����������\n";
                    
                    break;
                }

                unsigned new_priority{ };
                std::wcout << L"������� ����� �������� ������� ������������: ";
                std::wcin >> new_priority;

                if (requests.at(id).get_priority() <= new_priority)
                {
                    std::wcout << L"�������� ��������: ����� ����� ������������ ������ ��� ����� ��������\n";

                    break;
                }

                requests_queue->decrease_key(requests.at(id), new_priority);

                std::wcout << L"����� ������������ ������ ��������\n";
            }
            break;

            case AppActions::EXIT:
            default:
                break;
        }

        std::wcout << std::endl << SEPARATOR << std::endl;
    }

    return EXIT_SUCCESS;
}