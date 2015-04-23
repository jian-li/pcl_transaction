#ifndef DATATYPES_H
#define DATATYPES_H
//#include <pcl/compression/compression_profiles.h>

#define OCOTOMAP_PROFILE_COUNT 12

struct octmapParamType
{
    /*Manul configuration*/
    double pointResolution;
    double octreeResolution;
    bool doVoxelGridDownSampling;
    unsigned int iFrameRate;
    unsigned char colorBitResolution;
    bool doColorEncoding;
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

const struct octmapParamType paramProfie[OCOTOMAP_PROFILE_COUNT] = {
    {
    // PROFILE: LOW_RES_ONLINE_COMPRESSION_WITHOUT_COLOR
       0.01, /* pointResolution = */
       0.01, /* octreeResolution = */
       true, /* doVoxelGridDownDownSampling = */
       50, /* iFrameRate = */
       4, /* colorBitResolution = */
       false /* doColorEncoding = */
    },
    {
    // PROFILE: LOW_RES_ONLINE_COMPRESSION_WITH_COLOR
        0.01, /* pointResolution = */
        0.01, /* octreeResolution = */
        true, /* doVoxelGridDownDownSampling = */
        50, /* iFrameRate = */
        4, /* colorBitResolution = */
        true /* doColorEncoding = */
    },
    {
    // PROFILE: MED_RES_ONLINE_COMPRESSION_WITHOUT_COLOR
        0.005, /* pointResolution = */
        0.01, /* octreeResolution = */
        false, /* doVoxelGridDownDownSampling = */
        40, /* iFrameRate = */
        5, /* colorBitResolution = */
        false /* doColorEncoding = */
    },
    {
    // PROFILE: MED_RES_ONLINE_COMPRESSION_WITH_COLOR
        0.005, /* pointResolution = */
        0.01, /* octreeResolution = */
        false, /* doVoxelGridDownDownSampling = */
        40, /* iFrameRate = */
        5, /* colorBitResolution = */
        true /* doColorEncoding = */
    },
    {
    // PROFILE: HIGH_RES_ONLINE_COMPRESSION_WITHOUT_COLOR
        0.0001, /* pointResolution = */
        0.01, /* octreeResolution = */
        false, /* doVoxelGridDownDownSampling = */
        30, /* iFrameRate = */
        7, /* colorBitResolution = */
        false /* doColorEncoding = */
    },
    {
    // PROFILE: HIGH_RES_ONLINE_COMPRESSION_WITH_COLOR
        0.0001, /* pointResolution = */
        0.01, /* octreeResolution = */
        false, /* doVoxelGridDownDownSampling = */
        30, /* iFrameRate = */
        7, /* colorBitResolution = */
        true /* doColorEncoding = */
    },
    {
    // PROFILE: LOW_RES_OFFLINE_COMPRESSION_WITHOUT_COLOR
        0.01, /* pointResolution = */
        0.01, /* octreeResolution = */
        true, /* doVoxelGridDownDownSampling = */
        100, /* iFrameRate = */
        4, /* colorBitResolution = */
        false /* doColorEncoding = */
    },
    {
    // PROFILE: LOW_RES_OFFLINE_COMPRESSION_WITH_COLOR
        0.01, /* pointResolution = */
        0.01, /* octreeResolution = */
        true, /* doVoxelGridDownDownSampling = */
        100, /* iFrameRate = */
        4, /* colorBitResolution = */
        true /* doColorEncoding = */
    },
    {
    // PROFILE: MED_RES_OFFLINE_COMPRESSION_WITHOUT_COLOR
        0.005, /* pointResolution = */
        0.005, /* octreeResolution = */
        true, /* doVoxelGridDownDownSampling = */
        100, /* iFrameRate = */
        5, /* colorBitResolution = */
        false /* doColorEncoding = */
    },
    {
    // PROFILE: MED_RES_OFFLINE_COMPRESSION_WITH_COLOR
        0.005, /* pointResolution = */
        0.01, /* octreeResolution = */
        false, /* doVoxelGridDownDownSampling = */
        100, /* iFrameRate = */
        5, /* colorBitResolution = */
        true /* doColorEncoding = */
    },
    {
    // PROFILE: HIGH_RES_OFFLINE_COMPRESSION_WITHOUT_COLOR
        0.0001, /* pointResolution = */
        0.0001, /* octreeResolution = */
        true, /* doVoxelGridDownDownSampling = */
        100, /* iFrameRate = */
        8, /* colorBitResolution = */
        false /* doColorEncoding = */
    },
    {
    // PROFILE: HIGH_RES_OFFLINE_COMPRESSION_WITH_COLOR
        0.0001, /* pointResolution = */
        0.01, /* octreeResolution = */
        false, /* doVoxelGridDownDownSampling = */
        100, /* iFrameRate = */
        8, /* colorBitResolution = */
        true /* doColorEncoding = */
    }
};

#endif // DATATYPES_H
