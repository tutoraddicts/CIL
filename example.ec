test1 = -5
test2 = "Hello World\n"
test3 = 5.0

say "Value of Test 1 : int : " test1 "\n"
say "Value of Test 2 : string : " test2
say "Value of Test 3 : float : " test3 "\n"

test1 = 14
test3 = 4.6
test2 = "Bye World\n"

say "\n"

say "Value of Test 1 : int : Changes TO> " test1 "\n"
say "Value of Test 3 : float : Changes TO> " test3 "\n"
say "Value of Test 2 : string : Changes TO> " test2

say "Printing them all together : " test1+" :: "+test3+" :: "+test2 

test1 = test3

say "Value Transferred From Test 1 To Test 2 : " test1 "\n"

say "This variable is not created : " test4

say "Test4 created: "

test4 = test2
say test4
