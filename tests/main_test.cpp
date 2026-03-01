#include <gtest/gtest.h>
#include "main.h"
#include "vector_functions.h"


using namespace std;


TEST(CatchingStringInIntVector, Subtest_1) {
    vector<int> int_vector;
    vector<string> command_vector = {"12312", "23", "12312", "231"};
    ERR_CODE code = get_int_vector(int_vector, command_vector);
EXPECT_EQ(code, S_OK);
}

TEST(CatchingStringInIntVector, Subtest_2) {
    vector<float> float_vector;
    vector<string> command_vector = {"12312", "23", "123.12", "231"};
    ERR_CODE code = get_float_vector(float_vector, command_vector);
EXPECT_EQ(code, S_OK);
}

TEST(CatchingStringInIntVector, Subtest_3) {
    vector<double> double_vector;
    vector<string> command_vector = {"12532", "23", "0000.12312", "231"};
    ERR_CODE code = get_double_vector(double_vector, command_vector);
    EXPECT_EQ(code, S_OK);
}

TEST(CatchingStringInIntVector, Subtest_4) {
    vector<int> int_vector;
    vector<string> command_vector = {"1231d2", "23", "12312", "231"};
    ERR_CODE code = get_int_vector(int_vector, command_vector);
    EXPECT_EQ(code, WARNING_CODE_VALUE);
}

TEST(CatchingStringInIntVector, Subtest_5) {
    vector<double> double_vector;
    vector<string> command_vector = {"12312", "23", "abc", "231"};
    ERR_CODE code = get_double_vector(double_vector, command_vector);
    EXPECT_EQ(code, WARNING_CODE_VALUE);
}

TEST(CatchingStringInIntVector, Subtest_6) {
    vector<float> float_vector;
    vector<string> command_vector = {"12312", "23", "9382.", "231"};
    ERR_CODE code = get_float_vector(float_vector, command_vector);
    EXPECT_EQ(code, WARNING_CODE_VALUE);
}

TEST(CatchingStringInIntVector, Subtest_7) {
    vector<int> int_vector;
    vector<string> command_vector = {"12312", "2863128736218361923", "12312", "231"};
    ERR_CODE code = get_int_vector(int_vector, command_vector);
    EXPECT_EQ(code, WARNING_CODE_OVERFLOW);
}


TEST(NoPrint_symbols, Subtest_1) {
    string command = "name nickname";
    vector<string> vector_command = split_string(command);
    vector<string> result_vector = {"name", "nickname"};
    EXPECT_EQ(vector_command, result_vector);
}


TEST(NoPrint_symbols, Subtest_2) {
    string command = "vector 123         masd  \n kakdela? \e \r barbos    \t 1\a  \f4\v5\b     6\n";
    vector<string> vector_command = split_string(command);
    vector<string> result_vector = {"vector", "123", "masd", "kakdela?", "barbos", "1", "4", "5", "6"};
    EXPECT_EQ(vector_command, result_vector);
}


TEST(FourthVector_sValueVectorNotNull, Subtest_int_1) {
    vector<int> int_vector;
    vector<string> command_vector = {"52", "822", "1373", "231"};
    ERR_CODE code = get_int_vector(int_vector, command_vector);
    EXPECT_EQ(code, S_OK);
}

TEST(FourthVector_sValueVectorNotNull, Subtest_int_2) {
    vector<int> int_vector;
    vector<string> command_vector = {"52", "822", "1373", "0"};
    ERR_CODE code = get_int_vector(int_vector, command_vector);
    EXPECT_EQ(code, WARNING_CODE_FOURTH_ELEMENT_IS_NULL);
}

TEST(FourthVector_sValueVectorNotNull, Subtest_float_1) {
    vector<float> float_vector;
    vector<string> command_vector = {"52.4", "82.2", "0.1373", "32.2"};
    ERR_CODE code = get_float_vector(float_vector, command_vector);
    EXPECT_EQ(code, S_OK);
}

TEST(FourthVector_sValueVectorNotNull, Subtest_float_2) {
    vector<float> float_vector;
    vector<string> command_vector = {"52.4", "82.2", "0.1373", "0"};
    ERR_CODE code = get_float_vector(float_vector, command_vector);
    EXPECT_EQ(code, WARNING_CODE_FOURTH_ELEMENT_IS_NULL);
}

TEST(FourthVector_sValueVectorNotNull, Subtest_double_1) {
    vector<double> double_vector;
    vector<string> command_vector = {"52.4", "82.2", "0.1373", "32.2"};
    ERR_CODE code = get_double_vector(double_vector, command_vector);
    EXPECT_EQ(code, S_OK);
}

TEST(FourthVector_sValueVectorNotNull, Subtest_double_2) {
    vector<double> double_vector;
    vector<string> command_vector = {"52.4", "82.2", "0.1373", "0"};
    ERR_CODE code = get_double_vector(double_vector, command_vector);
    EXPECT_EQ(code, WARNING_CODE_FOURTH_ELEMENT_IS_NULL);
}

TEST(FourthVector_sValueVectorNotNull, Subtest_bool_1) {
    vector<bool> bool_vector;
    vector<string> command_vector = {"true", "false", "false", "true"};
    ERR_CODE code = get_bool_vector(bool_vector, command_vector);
    EXPECT_EQ(code, S_OK);
}

TEST(FourthVector_sValueVectorNotNull, Subtest_bool_2) {
    vector<bool> bool_vector;
    vector<string> command_vector = {"true", "false", "false", "false"};
    ERR_CODE code = get_bool_vector(bool_vector, command_vector);
    EXPECT_EQ(code, S_OK);
}

TEST(FourthVector_sValueVectorNotNull, Subtest_char_1) {
    vector<char> char_vector;
    vector<string> command_vector = {"а", "3", "ы   ", "dfs"};
    ERR_CODE code = get_char_vector(char_vector, command_vector);
    EXPECT_EQ(code, S_OK);
}

TEST(FourthVector_sValueVectorNotNull, Subtest_char_2) {
    vector<char> char_vector;
    vector<string> command_vector = {"а", "3", "ы", "0"};
    ERR_CODE code = get_char_vector(char_vector, command_vector);
    EXPECT_EQ(code, S_OK);
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    auto numFailedTests = RUN_ALL_TESTS();
    return numFailedTests;
}
