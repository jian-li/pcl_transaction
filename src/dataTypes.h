#ifndef DATATYPES_H
#define DATATYPES_H
#include <pcl/compression/compression_profiles.h>

struct octmapParamType
{
    /*Manul configuration*/
    struct compressionProfiles_t * confProfileParam;
};

struct filterParamType
{
    double xAxisDown;
    double xAxisUp;
    bool xAxisSelected;
    double yAxisDown;
    double yAxisUp;
    bool yAxisSelected;
    double ZAxisDown;
    double zAxisUp;
    bool zAxisSelected;
    double xleafSize;
    double yleafSize;
    double zleafSize;
};

struct meshParamType
{

};

#endif // DATATYPES_H
