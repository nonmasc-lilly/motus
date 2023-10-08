
#ifndef MOV_H

#define MOVPOS float
#define UNCHANGED -0.5
#define EDIRECTION enum DIRECTION

enum DIRECTION {
    DTOPLEFT=1, DTOPMID=2, DTOPRIGHT=3,
    DMIDLEFT=4, DNONE=0,   DMIDRIGHT=5,
    DBOTLEFT=6, DBOTMID=7, DBOTRIGHT=8,
    DERROR=-1,
};

struct coord {int x, y;};
struct bound {struct coord min, max;};

struct coord ip2crd(int *ip);

int mov(struct coord *target, MOVPOS x, MOVPOS y);
int sld(struct coord *target, MOVPOS x, MOVPOS y);

EDIRECTION direction(int x, int y);
EDIRECTION constrain(struct coord *target, struct bound bounds);
EDIRECTION movb(struct coord *target, MOVPOS x, MOVPOS y, struct bound bounds);
EDIRECTION sldb(struct coord *target, MOVPOS x, MOVPOS y, struct bound bounds);

#endif
