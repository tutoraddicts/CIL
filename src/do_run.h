#pragma once

#ifndef DO_RUN_H
#define DO_RUN_H

#include "definations.h"
#include "identify_instruction/identify_instruction.h"
#include "variable/CreateVariable.h"
#include "variable/FindVariable.h"
#include "predefined_functions/predefined_functions.h"

/*
 do_run is the function where actual work going on so if you want to change anythin look into
 do_run you can skip main function
*/
DO_RUN_H void do_run(String data);

#endif