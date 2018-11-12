#ifndef __CONFIG_H__
#define __CONFIG_H__

struct Config {
    static int unit_id;

    Config();

    static void init();

    static int getNextId();

};

#endif //__CONFIG_H__
