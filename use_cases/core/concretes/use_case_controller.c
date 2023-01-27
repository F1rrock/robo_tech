#include "../headers/use_case_controller.h"
#include "use_case_node.c"
#include <stdlib.h>

struct use_case_controller_properties
{
    use_case_node *nodes;
    int used;
    int size;
};

void addCase(const struct use_case_controller *self, const int key, const use_case value)
{
    if (self->properties->used >= self->properties->size)
    {
        self->properties->size *= 2;
        self->properties->nodes = 
            (use_case_node *) realloc(self->properties->nodes, sizeof(use_case_node) * self->properties->size);
    }
    use_case_node node = (use_case_node) malloc(sizeof(struct use_case_node));
    node->key = key;
    node->value = value;
    self->properties->nodes[self->properties->used ++] = node;
}

use_case getCaseByCode(const struct use_case_controller *self, const int key)
{
    for (int i = 0; i < self->properties->used; i ++)
    {
        use_case_node node = self->properties->nodes[i];
        if (node->key == key)
        {
            return node->value;
        }
    }
    return NULL;
}

struct use_case_controller use_case_controller()
{
    properties *ptr = (properties *) malloc(sizeof(properties));
    ptr->size = DEFAULT_LENGTH;
    ptr->nodes = (use_case_node *) malloc(sizeof(use_case_node) * DEFAULT_LENGTH);
    ptr->used = 0;
    return (struct use_case_controller) { ptr, addCase, getCaseByCode };
}

void destruct(struct use_case_controller *self)
{
    for (int i = 0; i < self->properties->used; i ++)
    {
        free(self->properties->nodes[i]);
    }
    free(self->properties->nodes);
    self->properties->size = self->properties->used = 0;
    free(self->properties);
    self->addCase = NULL;
    self->getCaseByCode = NULL;
}