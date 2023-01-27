#include "use_cases/core/headers/use_case_controller.h"
#include "dependency_injection/headers/set_up_use_case_controller.h"
#include <stdlib.h>

int main()
{
    struct use_case_controller controller = setUpUseCaseController();
    int code = 1;
    use_case execute = controller.getCaseByCode(&controller, code);
    if (execute != NULL)
    {
        execute();
    }
    destruct(&controller);
    return 0;
}