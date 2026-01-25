#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <climits>
#include <cfloat>

static int doTests();

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		doTests();
		return 0;
	}
	ScalarConverter::convert(static_cast<std::string>(argv[1]));
	return 0;
}

static void test(const std::string &literal)
{
    std::cout << "==============================" << std::endl;
    std::cout << "Input literal: \"" << literal << "\"" << std::endl;
    ScalarConverter::convert(literal);

}

static int doTests()
{
    /* ================= char ================= */
    test("a");          // printable char
    test("z");
    test("0");          // digit char
    test(" ");          // space
    test("\n");         // non-displayable (may be tricky)
    test("127");        // DEL (non displayable char)

    /* ================= int ================== */
    test("0");
    test("42");
    test("-42");
    test("2147483647");     // INT_MAX
    test("-2147483648");    // INT_MIN
    test("2147483648");     // overflow
    test("-2147483649");    // underflow

    /* ================= float ================ */
    test("0.0f");
    test("42.0f");
    test("-42.0f");
    test("3.4028235e+38f"); // FLT_MAX
    test("-3.4028235e+38f");
    test("1.17549435e-38f");// FLT_MIN
    test("nanf");
    test("+inff");
    test("-inff");

    /* ================= double =============== */
    test("0.0");
    test("42.0");
    test("-42.0");
    test("1.7976931348623157e+308"); // DBL_MAX
    test("-1.7976931348623157e+308");
    test("2.2250738585072014e-308"); // DBL_MIN
    test("nan");
    test("+inf");
    test("-inf");

    /* ============ weird / invalid =========== */
    test("abc");
    test("42ff");
    test("..");
    test("");

    return 0;
}
