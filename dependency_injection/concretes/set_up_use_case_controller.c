#include "../headers/set_up_use_case_controller.h"
#include "../../use_cases/core/headers/use_case_controller.h"

#include "../../use_cases/features/headers/code_is_zero_case.h"
#include "../../use_cases/features/headers/code_is_one_case.h"

struct use_case_controller setUpUseCaseController(void)
{
    struct use_case_controller controller = use_case_controller();
    controller.addCase(&controller, 0, codeIsZeroCase);
    controller.addCase(&controller, 1, codeIsOneCase);
    return controller;
}