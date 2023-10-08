#include "mov.h"

int mov(struct coord *target, MOVPOS x, MOVPOS y) {
    if(x != UNCHANGED) target->x = (int)x;
    if(y != UNCHANGED) target->y = (int)y;
}

int sld(struct coord *target, MOVPOS x, MOVPOS y) {
    if(x != UNCHANGED) target->x += (int)x;
    if(y != UNCHANGED) target->y += (int)y;
}

struct coord ip2crd(int *ip) {
    struct coord ret = { ip[0], ip[1] };
    return ret;
}

EDIRECTION movb(struct coord *target, MOVPOS x, MOVPOS y, struct bound bounds) {
    if(x != UNCHANGED) target->x = (int)x;
    if(y != UNCHANGED) target->y = (int)y;

    return constrain(target, bounds);
}

EDIRECTION sldb(struct coord *target, MOVPOS x, MOVPOS y, struct bound bounds) {
    if(x != UNCHANGED) target->x += (int)x;
    if(y != UNCHANGED) target->y += (int)y;

    return constrain(target, bounds);
}

EDIRECTION direction(int x, int y) {
    x = (x == 0 ? (0) : (x < 0 ? (-1) : (1)));
    y = (y == 0 ? (0) : (y < 0 ? (-1) : (1)));
    switch(x) {
    case -1: switch(y) {
        case -1: return DBOTLEFT;
        case  0: return DMIDLEFT;
        case  1: return DTOPLEFT;
        } break;
    case  0: switch(y) {
        case -1: return DBOTMID;
        case  0: return DNONE;
        case  1: return DTOPMID;
        } break;
    case  1: switch(y) {
        case -1: return DBOTRIGHT;
        case  0: return DMIDRIGHT;
        case  1: return DTOPRIGHT;
        } break;
    }
    return DERROR;
}

EDIRECTION constrain(struct coord *target, struct bound bounds) {
    int _x = 0;
    int _y = 0;

    if(target->x < bounds.min.x) {
        target->x = bounds.min.x;
        _x = -1;
    }

    if(target->x > bounds.max.x) {
        target->x = bounds.max.x;
        _x = 1;
    }

    if(target->y < bounds.min.y) {
        target->y = bounds.min.y;
        _y = -1;
    }

    if (target->y > bounds.max.y) {
        target->y = bounds.max.y;
        _y = 1;
    }

    return direction(_x, _y);
}
