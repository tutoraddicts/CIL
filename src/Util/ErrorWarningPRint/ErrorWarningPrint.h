#pragma once

#define Error(error, eargs...) printf("\033[0;31m");printf(error, eargs);printf("\033[0m");

#define Warning(warning, wargs...) printf("\033[0;33m");printf(warning, wargs);printf("\033[0m");