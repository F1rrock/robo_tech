#ifndef USE_CASE_CONTROLLER_H
#define USE_CASE_CONTROLLER_H

#include "use_case_node.h"

typedef struct use_case_controller_properties properties;

struct use_case_controller
{
    properties *properties;
    void (*addCase)(const struct use_case_controller*, const int key, const use_case value);
    use_case (*getCaseByCode)(const struct use_case_controller*, const int key);
};

#define DEFAULT_LENGTH 5
struct use_case_controller use_case_controller();
void destruct(struct use_case_controller *self);

void addCase(const struct use_case_controller *self, const int key, const use_case value);
use_case getCaseByCode(const struct use_case_controller *self, const int key);

#endif