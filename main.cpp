#include <iostream>
#include <vector>
#include <filesystem>
#include "user.h"

template <typename T> void load_data_from_file(const std::string& file_name, std::vector<T>& data_vector) 
{
    std::ifstream read_file(file_name);

    if (!read_file.is_open())
    {
        std::cerr << "can't read file : " + file_name << std::endl;
        return;
    }
    
    T data;

    while (read_file >> data)
    {
        data_vector.push_back(data);
    }

    read_file.close();
}

template <typename T> void save_data_to_file(const std::string& file_name, const std::vector<T>& data_vector) 
{
    std::ofstream write_file(file_name, std::ios::app);

    if (!write_file.is_open())
    {
        std::cerr << "can't write file : " + file_name << std::endl;
        return;
    }

    for (auto data : data_vector) 
    {
        write_file << data;
    }

    write_file.close();
}

void set_file_permissions(const std::string& file_name)
{
    namespace fs = std::filesystem;

    fs::path p(file_name);
    if (std::filesystem::exists(p)) 
    {
        fs::permissions(file_name, fs::perms::owner_read | fs::perms::owner_write, fs::perm_options::add);
        fs::permissions(file_name, fs::perms::group_all | fs::perms::others_all, fs::perm_options::remove);
    }
    else
    {
        std::cerr << "not find file : " + file_name << std::endl;
    
    }
}

int main()
{
    const std::string messages_file_name = "messages.txt";
    const std::string users_file_name = "users.txt";

    std::vector<Message> messages;
    std::vector<User> users;

    load_data_from_file(users_file_name, users);
    load_data_from_file(messages_file_name, messages);

    users.push_back(User{"1","1","1"});
    users.push_back(User{"2_2","2","2"});
    users.push_back(User{"3 3","3","3"});

    messages.push_back(Message{"1", "2_2", "text 1"});
    messages.push_back(Message{"2_2", "3 3", "text 2"});
    messages.push_back(Message{"3 3", "1", "text 3"});

    save_data_to_file(users_file_name, users);
    save_data_to_file(messages_file_name, messages);

    set_file_permissions(users_file_name);
    set_file_permissions(messages_file_name);

    return 0;
}