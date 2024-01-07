#include <string>
#include <iostream>
#include <vector>


constexpr unsigned int max_set_size = 1000;
constexpr unsigned int max_number = 300;



std::vector<unsigned int> generate_random_number_set()
{
    unsigned int generated_size = rand() % (max_set_size + 1);
    std::vector<unsigned int> result(generated_size);

    for(unsigned int i=0; i<generated_size; ++i)
        result[i] = ( rand() % max_number) + 1;

    return result;
}



std::string serialize_number_set(const std::vector<unsigned int>& _set)
{
    unsigned int numbers_amounts[max_number + 1] = { 0 };

    for(unsigned int i=0; i<_set.size(); ++i)
        ++numbers_amounts[_set[i]];

    std::string result;
    result.resize(max_number * 2);

    for(unsigned int i=1; i<max_number + 1; ++i)
    {
        char* number_as_chars = (char*)&numbers_amounts[i];

        unsigned int str_i = (i - 1) * 2;
        result[str_i] = number_as_chars[0];
        result[str_i + 1] = number_as_chars[1];
    }

    return result;
}

std::vector<unsigned int> deserialize_number_set(const std::string& _str)
{
    unsigned int total_amount = 0;
    unsigned int numbers_amounts[max_number + 1] = { 0 };

    for(unsigned int i=1; i<max_number + 1; ++i)
    {
        char* number_as_chars = (char*)&numbers_amounts[i];

        unsigned int str_i = (i - 1) * 2;
        number_as_chars[0] = _str[str_i];
        number_as_chars[1] = _str[str_i + 1];

        total_amount += numbers_amounts[i];
    }

    std::vector<unsigned int> result(total_amount);

    unsigned int result_i = 0;
    for(unsigned int i=1; i<max_number + 1; ++i)
    {
        for(unsigned int number_i=0; number_i<numbers_amounts[i]; ++number_i)
        {
            result[result_i] = i;
            ++result_i;
        }
    }

    return result;
}



int main()
{
    srand(time(nullptr));

    std::vector<unsigned int> random_set = generate_random_number_set();

    std::cout << "initial set:\n";
    for(unsigned int i=0; i<random_set.size(); ++i)
        std::cout << random_set[i] << " ";
    std::cout << "\n";

    std::string serialized_set = serialize_number_set(random_set);

    std::vector<unsigned int> deserialized_set = deserialize_number_set(serialized_set);

    std::cout << "serialized-deserialized set:\n";
    for(unsigned int i=0; i<deserialized_set.size(); ++i)
        std::cout << deserialized_set[i] << " ";
    std::cout << "\n";

    return 0;
}
