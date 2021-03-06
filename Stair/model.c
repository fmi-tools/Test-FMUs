#include "config.h"
#include "model.h"


void setStartValues(ModelInstance *comp) {
    M(counter) = 1;
    
    // TODO: move this to initialize()?
    comp->nextEventTime        = 1;
    comp->nextEventTimeDefined = true;
}

void calculateValues(ModelInstance *comp) {
    // do nothing
}

Status getInt32(ModelInstance* comp, ValueReference vr, int *value, size_t *index) {
    switch (vr) {
        case vr_counter:
            value[(*index)++] = M(counter);
            return OK;
        default:
            return Error;
    }
}

void eventUpdate(ModelInstance *comp) {
    
    if (comp->nextEventTimeDefined && comp->time >= comp->nextEventTime) {
        M(counter)++;
        comp->nextEventTime += 1;
    }
    
    comp->valuesOfContinuousStatesChanged   = false;
    comp->nominalsOfContinuousStatesChanged = false;
    comp->terminateSimulation               = false;
    comp->nextEventTimeDefined              = true;
}
