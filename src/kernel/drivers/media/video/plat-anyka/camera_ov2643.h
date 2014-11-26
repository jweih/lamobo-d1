/**
 * @file camera_ov2643.h
 * @brief camera driver file
 * Copyright (C) 2011 Anyka (Guangzhou) Microelectronics Technology Co., Ltd
 * @author xia_wenting 
 * @date 2011-10-26
 * @version 1.0
 * @ref
 */
#ifndef __CAMERA_OV2643_H__
#define __CAMERA_OV2643_H__


#if defined (USE_CAMERA_OV2643) || defined (CONFIG_SENSOR_OV2643)

#undef DELAY_FLAG
#undef END_FLAG
#define DELAY_FLAG        0xfd   // first parameter is 0xfe, then 2nd parameter is delay time count
#define END_FLAG          0xfe   // first parameter is 0xff, then parameter table is over 

static const T_U8 INIT_TAB[] = 
{
    //640*480, mclk 24mhz, pclk 72mhz, 30fps
    0x12, 0x80,
    0xc3, 0x1f,
    0xc4, 0xff,
    0x3d, 0x48,
    0xdd, 0xa5,
    //windows setup
    0x20, 0x01,
    0x21, 0x98,
    0x22, 0x00,
    0x23, 0x06,
    0x24, 0x28,//0x280=640
    0x25, 0x04,
    0x26, 0x1e,//0x1e0=480
    0x27, 0x04,
    0x28, 0x40,

    //format setting
    0x12, 0x09,
    0x39, 0xd0,
    0xcd, 0x13,
    //frame setting
    0x0e, 0x10,
    0x0f, 0x14,
    0x10, 0x0a,
    0x11, 0x00,
    0x29, 0x07,//dummy pixels
    0x2a, 0x93,
    0x2b, 0x02,//dummy lines
    0x2c, 0x6a,
    0x1d, 0x03,
    0x1e, 0x00,
    0x1f, 0xb9,

    0x13, 0xff,
    0x14, 0xa7,
    0x15, 0x42,
    0x3c, 0xa4,
    0x18, 0x60,
    0x19, 0x50,
    0x1a, 0xe2,
    0x37, 0xe8,
    0x16, 0x90,
    0x43, 0x00,
    0x40, 0xfb,
    0xa9, 0x44,
    0x2f, 0xec,
    0x35, 0x10,
    0x36, 0x10,
    0x0c, 0x00,
    0x0d, 0x20,
    0xd0, 0x93,
    0xdc, 0x2b,
    0xd9, 0x41,
    0xd3, 0x02,
    0xde, 0x7c,
    0x3d, 0x08,
    0x0c, 0x00,
    0x18, 0x2c,
    0x19, 0x24,
    0x1a, 0x71,
    0x9b, 0x69,
    0x9c, 0x7d,
    0x9d, 0x7d,
    0x9e, 0x69,
    0x35, 0x04,
    0x36, 0x04,
    //gamma
    0x65, 0x04,
    0x66, 0x07,
    0x67, 0x19,
    0x68, 0x34,
    0x69, 0x4a,
    0x6a, 0x5a,
    0x6b, 0x67,
    0x6c, 0x71,
    0x6d, 0x7c,
    0x6e, 0x8c,
    0x6f, 0x9b,
    0x70, 0xa9,
    0x71, 0xc0,
    0x72, 0xd5,
    0x73, 0xe8,
    0x74, 0x20,
    //color matrix
    0xab, 0x28,
    0xac, 0x48,
    0xad, 0x10,
    0xae, 0x12,
    0xaf, 0x76,
    0xb0, 0x88,
    0xb1, 0x80,
    0xb2, 0x88,
    0xb3, 0x08,
    0xb4, 0x98,
    0xb5, 0x00,
    //lens shading
    0x40, 0xfb,
    0x4c, 0x03,
    0x4d, 0x40,
    0x4e, 0x02,
    0x4f, 0x63,
    0x50, 0x44,
    0x51, 0x20,
    0x52, 0x66,
    0x53, 0x03,
    0x54, 0x34,
    0x55, 0x02,
    0x56, 0x5c,
    0x57, 0x38,
    0x58, 0x00,
    0x59, 0x66,
    0x5a, 0x03,
    0x5b, 0x20,
    0x5c, 0x02,
    0x5d, 0x5c,
    0x5e, 0x36,
    0x5f, 0x00,
    0x60, 0x66,
    0x41, 0x1f,
    0xb6, 0x02,
    0xb9, 0x40,
    0xba, 0x28,
    0xbf, 0x0c,
    0xc0, 0x3e,
    0xa3, 0x0a,
    0xa4, 0x0f,
    0xa5, 0x10,
    0xa6, 0x16,
    0x9f, 0x0a,
    0xa0, 0x0f,
    0xa7, 0x0a,
    0xa8, 0x0f,
    0xa1, 0x18,
    0xa2, 0x10,
    0xa9, 0x00,
    0xaa, 0xa6,
    //awb
    0x75, 0x68,
    0x76, 0x11,
    0x77, 0x92,
    0x78, 0x21,
    0x79, 0xe1,
    0x7a, 0x02,
    0x7c, 0x0e,
    0x7d, 0x12,
    0x7e, 0x12,
    0x7f, 0x54,
    0x80, 0x78,
    0x81, 0xa2,
    0x82, 0x80,
    0x83, 0x4e,
    0x84, 0x40,
    0x85, 0x4c,
    0x86, 0x53,
    0x87, 0xf8,
    0x88, 0x08,
    0x89, 0x70,
    0x8a, 0xf0,
    0x8b, 0xf0,

    END_FLAG, END_FLAG
};

static const T_U8 UXGA_MODE_TAB[] = 
{
#if 1
    //1600*1200, mclk 24mhz, pclk 72mhz, 15fps, with no lcd
    0x3d, 0x48,
    //windows setup
    0x20, 0x01,
    0x21, 0x25,
    0x22, 0x00,
    0x23, 0x0c,
    0x24, 0x64, //0x640=1600
    0x25, 0x08,
    0x26, 0x4b, //0x4b0=1200
    0x27, 0x06,
    0x28, 0x42,
    //format setting
    0x12, 0x08,
    0x39, 0x10,
    0xcd, 0x12,

    0x3d, 0x08,
    //frame setting
    0x0e, 0x10,
    0x0f, 0x14,
    0x10, 0x0a, 
    0x11, 0x00,
    0x29, 0x07, //dummy pixels
    0x2a, 0x93,
    0x2b, 0x04, //dummy lines
    0x2c, 0xd4,
    0x1d, 0x06, //banding 
    0x1e, 0x00,
    0x1f, 0xb9,
    //other setting
    0xde, 0xc4,
#else
    //1600*1200, mclk 24mhz, pclk 36mhz, 7.5fps
    0x3d, 0x48,
    //windows setup
    0x20, 0x01,
    0x21, 0x25,
    0x22, 0x00,
    0x23, 0x0c,
    0x24, 0x64,
    0x25, 0x08,
    0x26, 0x4b,
    0x27, 0x06,
    0x28, 0x42,
    //format setting
    0x12, 0x08,
    0x39, 0x10,
    0xcd, 0x12,

    0x3d, 0x08,
    //frame setting
    0x0e, 0x10,
    0x0f, 0x14,
    0x10, 0x0a, 
    0x11, 0x01,
    0x29, 0x07, //dummy pixels
    0x2a, 0x93,
    0x2b, 0x04, //dummy lines
    0x2c, 0xd4,
    0x1d, 0x0c, //banding 
    0x1e, 0x00,
    0x1f, 0x5d,
    //other setting
    0xde, 0xc4,
#endif
    END_FLAG, END_FLAG
};

static const T_U8 SXGA_MODE_TAB[] = 
{
    //1280*1024, mclk 24mhz, pclk 36mhz, 15fps
    0x3d, 0x48,
    //windows setup
    0x20, 0x01,
    0x21, 0x25,
    0x22, 0x00,
    0x23, 0x0c,
    0x24, 0x50, //0x500=1280
    0x25, 0x08,
    0x26, 0x40, //0x400=1024
    0x27, 0x06,
    0x28, 0x42,
    //format setting
    0x12, 0x08,
    0x39, 0x10,
    0xcd, 0x12,

    0x3d, 0x08,
    //frame setting
    0x0e, 0x10,
    0x0f, 0x14,
    0x10, 0x0a, 
    0x11, 0x00,
    0x29, 0x07, //dummy pixels
    0x2a, 0x93,
    0x2b, 0x04, //dummy lines
    0x2c, 0xd4,
		0x1d, 0x06, //banding 
		0x1e, 0x00,
		0x1f, 0xb9,

    //other setting
    0xde, 0xc4,
    END_FLAG, END_FLAG
};



static const T_U8 VGA_MODE_TAB[] = 
{
    END_FLAG, END_FLAG
};

static const T_U8 CIF_MODE_TAB[] = 
{

    END_FLAG, END_FLAG
};

static const T_U8 QVGA_MODE_TAB[] = 
{
   
    END_FLAG, END_FLAG
};

static const T_U8 QCIF_MODE_TAB[] = 
{

    END_FLAG, END_FLAG
};

static const T_U8 QQVGA_MODE_TAB[] = 
{
    END_FLAG, END_FLAG
};

static const T_U8 PREV_MODE_TAB[] = 
{    
    //640*480, mclk 24mhz, pclk 72mhz, 30fps
    0x3d, 0x48,
    //windows setup
    0x20, 0x01,
    0x21, 0x98,
    0x22, 0x00,
    0x23, 0x06,
    0x24, 0x28,//0x280=640
    0x25, 0x04,
    0x26, 0x1e,//0x1e0=480
    0x27, 0x04,
    0x28, 0x40,
    //format setting
    0x12, 0x09,
    0x39, 0xd0,
    0xcd, 0x13,
    0x3d, 0x08,
    //frame setting
    0x0e, 0x10,
    0x0f, 0x14,
    0x10, 0x0a,
    0x11, 0x00,
    0x29, 0x07,//dummy pixels
    0x2a, 0x93,
    0x2b, 0x02,//dummy lines
    0x2c, 0x6a,
    0x1d, 0x03,
    0x1e, 0x00,
    0x1f, 0xb9,
    //other setting
    0xde, 0x7c,
    END_FLAG, END_FLAG
};

static const T_U8 RECORD_MODE_TAB[] = 
{
    //640*480, mclk 24mhz, pclk 72mhz, 25fps
    0x12, 0x80,
    0xc3, 0x5F,
    0xc4, 0xff,
    0x3d, 0x48,
    0xdd, 0xa5,
    //windows setup
    0x20, 0x01,
    0x21, 0x98,
    0x22, 0x00,
    0x23, 0x06,
    0x24, 0x28,//0x280=640
    0x25, 0x04,
    0x26, 0x1e,//0x1e0=480
    0x27, 0x04,
    0x28, 0x40,
    //format setting
    0x12, 0x09,
    0x39, 0xd0,
    0xcd, 0x13,
    //frame setting
    0x0e, 0x10,
    0x0f, 0x14,
    0x10, 0x0a,
    0x11, 0x00,
    0x29, 0x07,//dummy pixels
    0x2a, 0x93,
    0x2b, 0x02,//dummy lines
    0x2c, 0xe6,
    0x1d, 0x04,
    0x1e, 0x00,
    0x1f, 0xb9,

    0x13, 0xff,
    0x14, 0xa7,
    0x15, 0x42,
    0x3c, 0xa4,
    0x18, 0x60,
    0x19, 0x50,
    0x1a, 0xe2,
    0x37, 0xe8,
    0x16, 0x90,
    0x43, 0x00,
    0x40, 0xfb,
    0xa9, 0x44,
    0x2f, 0xec,
    0x35, 0x10,
    0x36, 0x10,
    0x0c, 0x00,
    0x0d, 0x20,
    0xd0, 0x93,
    0xdc, 0x2b,
    0xd9, 0x41,
    0xd3, 0x02,
    0xde, 0x7c,
    0x3d, 0x08,
    0x0c, 0x00,
    0x18, 0x34, //3C, //2c,
    0x19, 0x2e, //34, //24,
    0x1a, 0x71, //82, //71,
    0x9b, 0x69,
    0x9c, 0x7d,
    0x9d, 0x7d,
    0x9e, 0x69,
    0x35, 0x04,
    0x36, 0x04,
    //gamma
    0x65, 0x04,
    0x66, 0x07,
    0x67, 0x19,
    0x68, 0x34,
    0x69, 0x4a,
    0x6a, 0x5a,
    0x6b, 0x67,
    0x6c, 0x71,
    0x6d, 0x7c,
    0x6e, 0x8c,
    0x6f, 0x9b,
    0x70, 0xa9,
    0x71, 0xc0,
    0x72, 0xd5,
    0x73, 0xe8,
    0x74, 0x20,
    //color matrix
    0xab, 0x28,
    0xac, 0x48,
    0xad, 0x10,
    0xae, 0x18,
    0xaf, 0x75,
    0xb0, 0x8c,
    0xb1, 0x8d,
    0xb2, 0x8c,
    0xb3, 0x00,
    0xb4, 0x98,
    0xb5, 0x00,
    //lens shading
    0x40, 0xfb,
    0x4c, 0x02,
    0x4d, 0x90,
    0x4e, 0x01,
    0x4f, 0x8c, 
    0x50, 0x55, 
    0x51, 0x00,
    0x52, 0x66,
    0x53, 0x02,
    0x54, 0x78,
    0x55, 0x01,
    0x56, 0x70,
    0x57, 0x44,
    0x58, 0x20,
    0x59, 0x66,
    0x5a, 0x02,
    0x5b, 0x78,
    0x5c, 0x01,
    0x5d, 0x88,
    0x5e, 0x44,
    0x5f, 0x00,
    0x60, 0x66,

    0x41, 0x1f,
    0xb6, 0x07,
    0xb9, 0x34,//3c saturation
    0xba, 0x28,
    0xb7, 0x90,
    0xb8, 0x08,
    0xbf, 0x0c,
    0xc0, 0x3e,
    0xa3, 0x0a,
    0xa4, 0x0f,
    0xa5, 0x10,
    0xa6, 0x16,
    0x9f, 0x0a,
    0xa0, 0x0f,
    0xa7, 0x0a,
    0xa8, 0x0f,
    0xa1, 0x18,
    0xa2, 0x10,
    0xa9, 0x00,
    0xaa, 0xa6,
    //awb
    0x75, 0x68,
    0x76, 0x11,
    0x77, 0x92,
    0x78, 0xa1,//21
    0x79, 0xe1,
    0x7a, 0x02,
    0x7c, 0x0e,
    0x7d, 0x12,
    0x7e, 0x12,
    0x7f, 0x54,
    0x80, 0x78,
    0x81, 0xa2,
    0x82, 0x80,
    0x83, 0x4e,
    0x84, 0x40,
    0x85, 0x4c,
    0x86, 0x43,
    0x87, 0xf8,
    0x88, 0x08,
    0x89, 0x70,
    0x8a, 0xf0,
    0x8b, 0xf0,
    END_FLAG, END_FLAG
};

static const T_U8 RECORD_720P_TAB[] = 
{
#if 1
    //mclk 24mhz, pclk 72mhz, 25fps
    0x12, 0x80,
    0xc3, 0x1f,
    0xc4, 0xff,
    0x3d, 0x48,
    0xdd, 0xa5,
    //windows setup
    0x20, 0x01,
    0x21, 0x25,
    0x22, 0x00,
    0x23, 0x0c,
    0x24, 0x50,//0x500=1280
    0x25, 0x08, 
    0x26, 0x2d,//0x2d0=720
    0x27, 0x04,

    0x28, 0x42,
    //format setting
    0x12, 0x48,
    0x39, 0x10,
    0xcd, 0x12,
    //frame setting
    0x0e, 0x10,
    0x0f, 0x14,
    0x10, 0x0a,
    0x11, 0x00,    
    0x29, 0x06,//dummy pixels
    0x2a, 0x40,
    0x2b, 0x03,//dummy lines
    0x2c, 0x84,
    0x1d, 0x04,
    0x1e, 0x00,
    0x1f, 0xe1,

    0x13, 0xff,
    0x14, 0xa7,
    0x15, 0x42,
    0x3c, 0xa4,
    0x18, 0x60,
    0x19, 0x50,
    0x1a, 0xe2,
    0x37, 0xe8,
    0x16, 0x90,
    0x43, 0x00,
    0x40, 0xfb,
    0xa9, 0x44,
    0x2f, 0xec,
    0x35, 0x10,
    0x36, 0x10,
    0x0c, 0x00,
    0x0d, 0x20,
    0xd0, 0x93,
    0xdc, 0x2b,
    0xd9, 0x41,
    0xd3, 0x02,
    0x3d, 0x08,
    0x0c, 0x00,
    0x18, 0x2c,
    0x19, 0x24,
    0x1a, 0x71,
    0x9b, 0x69,
    0x9c, 0x7d,
    0x9d, 0x7d,
    0x9e, 0x69,
    0x35, 0x04,
    0x36, 0x04,
    //gamma0x
    0x65, 0x04,
    0x66, 0x07,
    0x67, 0x19,
    0x68, 0x34,
    0x69, 0x4a,
    0x6a, 0x5a,
    0x6b, 0x67,
    0x6c, 0x71,
    0x6d, 0x7c,
    0x6e, 0x8c,
    0x6f, 0x9b,
    0x70, 0xa9,
    0x71, 0xc0,
    0x72, 0xd5,
    0x73, 0xe8,
    0x74, 0x20,
    //color matrix
    0xab, 0x28, 
    0xac, 0x48, 
    0xad, 0x10, 
    0xae, 0x18, 
    0xaf, 0x75, 
    0xb0, 0x8c,
    0xb1, 0x8d,
    0xb2, 0x8c,
    0xb3, 0x00, 
    0xb4, 0x98, 
    0xb5, 0x00,
    //lens shading
    0x40, 0xfb,
    0x4c, 0x02,
    0x4d, 0x90,
    0x4e, 0x01,
    0x4f, 0x78,    
    0x50, 0x54,    
    0x51, 0x28,
    0x52, 0x66,
    0x53, 0x02,
    0x54, 0x92,
    0x55, 0x01,
    0x56, 0x70,
    0x57, 0x44,
    0x58, 0x20,
    0x59, 0x66,
    0x5a, 0x02,
    0x5b, 0x90,
    0x5c, 0x01,
    0x5d, 0x88,
    0x5e, 0x44,
    0x5f, 0x00,
    0x60, 0x66,

    0x41, 0x1f,
    0xb6, 0x07,
    0xb9, 0x34,//3c saturation
    0xba, 0x28,
    0xb7, 0x90,
    0xb8, 0x08,
    0xbf, 0x0c,
    0xc0, 0x3e,
    0xa3, 0x0a,
    0xa4, 0x0f,
    0xa5, 0x10,
    0xa6, 0x16,
    0x9f, 0x0a,
    0xa0, 0x0f,
    0xa7, 0x0a,
    0xa8, 0x0f,
    0xa1, 0x18,
    0xa2, 0x10,
    0xa9, 0x00,
    0xaa, 0xa6,
    //awb
    0x75, 0x68,
    0x76, 0x11,
    0x77, 0x92,
    0x78, 0xa1, //21
    0x79, 0xe1,
    0x7a, 0x02,
    0x7c, 0x0e,
    0x7d, 0x12,
    0x7e, 0x12,
    0x7f, 0x54,
    0x80, 0x78,
    0x81, 0xa2,
    0x82, 0x80,
    0x83, 0x4e,
    0x84, 0x40,
    0x85, 0x4c,
    0x86, 0x43,
    0x87, 0xf8,
    0x88, 0x08,
    0x89, 0x70,
    0x8a, 0xf0,
    0x8b, 0xf0,
#else
    //mclk 24mhz, pclk 48mhz, 20fps
    0x12, 0x80,
    0xc3, 0x5F,
    0xc4, 0xff,
    0x3d, 0x48,
    0xdd, 0xa5,
    //windows setup
    0x20, 0x01,
    0x21, 0x25,
    0x22, 0x00,
    0x23, 0x0c,
    0x24, 0x50,//0x500=1280
    0x25, 0x08,
    0x26, 0x2d,//0x2d0=720
    0x27, 0x04,
    0x28, 0x42,
    //format setting
    0x12, 0x48,
    0x39, 0x10,
    0xcd, 0x12,
    //frame setting
    0x0e, 0x10,
    0x0f, 0x24,
    0x10, 0x0a,
    0x11, 0x82,
    0x29, 0x06,//dummy pixels
    0x2a, 0x40,
    0x2b, 0x02,//dummy lines
    0x2c, 0xee,
    0x1d, 0x05,
    0x1e, 0x00,
    0x1f, 0x96,

    0x13, 0xff,
    0x14, 0xa7,
    0x15, 0x42,
    0x3c, 0xa4,
    0x18, 0x60,
    0x19, 0x50,
    0x1a, 0xe2,
    0x37, 0xe8,
    0x16, 0x90,
    0x43, 0x00,
    0x40, 0xfb,
    0xa9, 0x44,
    0x2f, 0xec,
    0x35, 0x10,
    0x36, 0x10,
    0x0c, 0x00,
    0x0d, 0x20,
    0xd0, 0x93,
    0xdc, 0x2b,
    0xd9, 0x41,
    0xd3, 0x02,
    0x3d, 0x08,
    0x0c, 0x00,
    0x18, 0x2c,
    0x19, 0x24,
    0x1a, 0x71,
    0x9b, 0x69,
    0x9c, 0x7d,
    0x9d, 0x7d,
    0x9e, 0x69,
    0x35, 0x04,
    0x36, 0x04,
    //gamma
    0x65, 0x04,
    0x66, 0x07,
    0x67, 0x19,
    0x68, 0x34,
    0x69, 0x4a,
    0x6a, 0x5a,
    0x6b, 0x67,
    0x6c, 0x71,
    0x6d, 0x7c,
    0x6e, 0x8c,
    0x6f, 0x9b,
    0x70, 0xa9,
    0x71, 0xc0,
    0x72, 0xd5,
    0x73, 0xe8,
    0x74, 0x20,
    //color matrix
    0xab, 0x28, 
    0xac, 0x48, 
    0xad, 0x10, 
    0xae, 0x18, 
    0xaf, 0x75, 
    0xb0, 0x8c,
    0xb1, 0x8d,
    0xb2, 0x8c,
    0xb3, 0x00, 
    0xb4, 0x98, 
    0xb5, 0x00,
    //lens shading
    0x40, 0xFB,
    0x4c, 0x02,
    0x4d, 0x90,
    0x4e, 0x01,
    0x4f, 0x78,    
    0x50, 0x54,    
    0x51, 0x28,
    0x52, 0x66,
    0x53, 0x02,
    0x54, 0x92,
    0x55, 0x01,
    0x56, 0x70,
    0x57, 0x44,
    0x58, 0x20,
    0x59, 0x66,
    0x5a, 0x02,
    0x5b, 0x90,
    0x5c, 0x01,
    0x5d, 0x88,
    0x5e, 0x44,
    0x5f, 0x00,
    0x60, 0x66,

    0x41, 0x1f,
    0xb6, 0x07,
    0xb9, 0x34,//3c saturation
    0xba, 0x28,
    0xb7, 0x90,
    0xb8, 0x08,
    0xbf, 0x0c,
    0xc0, 0x3e,
    0xa3, 0x0a,
    0xa4, 0x0f,
    0xa5, 0x10,
    0xa6, 0x16,
    0x9f, 0x0a,
    0xa0, 0x0f,
    0xa7, 0x0a,
    0xa8, 0x0f,
    0xa1, 0x18,
    0xa2, 0x10,
    0xa9, 0x00,
    0xaa, 0xa6,
    //awb
    0x75, 0x68,
    0x76, 0x11,
    0x77, 0x92,
    0x78, 0xa1,//21
    0x79, 0xe1,
    0x7a, 0x02,
    0x7c, 0x0e,
    0x7d, 0x12,
    0x7e, 0x12,
    0x7f, 0x54,
    0x80, 0x78,
    0x81, 0xa2,
    0x82, 0x80,
    0x83, 0x4e,
    0x84, 0x40,
    0x85, 0x4c,
    0x86, 0x43,
    0x87, 0xf8,
    0x88, 0x08,
    0x89, 0x70,
    0x8a, 0xf0,
    0x8b, 0xf0,
#endif
    END_FLAG, END_FLAG
};


/****************   Camera Exposure Table   ****************/
static const T_U8 EXPOSURE_WHOLE_TAB[] = 
{
    END_FLAG, END_FLAG
};

static const T_U8 EXPOSURE_CENTER_TAB[] = 
{
    END_FLAG, END_FLAG
};

static const T_U8 EXPOSURE_MIDDLE_TAB[] = 
{
    END_FLAG, END_FLAG
};

/****************   Camera Brightness Table   ****************/
static const T_U8 BRIGHTNESS_0_TAB[] = 
{
    //Brightness -3
    0xbd, 0x30,
    0xbe, 0x08,
    END_FLAG, END_FLAG
};

static const T_U8 BRIGHTNESS_1_TAB[] = 
{
    //Brightness -2
    0xbd, 0x20,
    0xbe, 0x08,
    END_FLAG, END_FLAG
};

static const T_U8 BRIGHTNESS_2_TAB[] = 
{
    //Brightness -1
    0xbd, 0x10,
    0xbe, 0x08,
    END_FLAG, END_FLAG
};

static const T_U8 BRIGHTNESS_3_TAB[] = 
{
    //Brightness 0
    0xbd, 0x00,
    0xbe, 0x00,
    END_FLAG, END_FLAG
};

static const T_U8 BRIGHTNESS_4_TAB[] = 
{
    //Brightness +1
    0xbd, 0x10,
    0xbe, 0x00,
    END_FLAG, END_FLAG
};

static const T_U8 BRIGHTNESS_5_TAB[] = 
{
    //Brightness +2 
    0xbd, 0x20,
    0xbe, 0x00,
    END_FLAG, END_FLAG
};

static const T_U8 BRIGHTNESS_6_TAB[] = 
{
    //Brightness +3
    0xbd, 0x30,
    0xbe, 0x00,
    END_FLAG, END_FLAG
};

/****************   Camera Contrast Table   ****************/
static const T_U8 CONTRAST_1_TAB[] = 
{
    //Contrast -3
    0xbb, 0x14,
    0xbc, 0x14,    
    END_FLAG, END_FLAG
};

static const T_U8 CONTRAST_2_TAB[] = 
{
    //Contrast -2
    0xbb, 0x18,
    0xbc, 0x18,    
    END_FLAG, END_FLAG
};

static const T_U8 CONTRAST_3_TAB[] = 
{
    //Contrast -1
    0xbb, 0x1c,
    0xbc, 0x1c,    
    END_FLAG, END_FLAG
};

static const T_U8 CONTRAST_4_TAB[] = 
{
    //Contrast 0
    0xbb, 0x20,
    0xbc, 0x20,
    END_FLAG, END_FLAG
};

static const T_U8 CONTRAST_5_TAB[] = 
{
    //Contrast +1
    0xbb, 0x24,
    0xbc, 0x24,    
    END_FLAG, END_FLAG
};

static const T_U8 CONTRAST_6_TAB[] = 
{
    //Contrast +2
    0xbb, 0x28,
    0xbc, 0x28,
    END_FLAG, END_FLAG
};

static const T_U8 CONTRAST_7_TAB[] = 
{
    //Contrast +3
    0xbb, 0x2c,
    0xbc, 0x2c,
    END_FLAG, END_FLAG
};

/****************   Camera Saturation Table   ****************/
static const T_U8 SATURATION_1_TAB[] = 
{
    //Saturation -2(0.5x)
    0xb9, 0x20,
    0xba, 0x20,
    END_FLAG, END_FLAG
};

static const T_U8 SATURATION_2_TAB[] = 
{
    //Saturation -1(0.75x)
    0xb9, 0x30,
    0xba, 0x30,
    END_FLAG, END_FLAG
};

static const T_U8 SATURATION_3_TAB[] = 
{ 
    //Saturation
    0xb9, 0x40,
    0xba, 0x40,
    END_FLAG, END_FLAG
};

static const T_U8 SATURATION_4_TAB[] = 
{ 
    //Saturation +1(1.25x)
    0xb9, 0x50,
    0xba, 0x50,
    END_FLAG, END_FLAG
};

static const T_U8 SATURATION_5_TAB[] = 
{
    //Saturation +2(1.75x)
    0xb9, 0x70,
    0xba, 0x70,
    END_FLAG, END_FLAG
};

/****************   Camera Sharpness Table   ****************/
static const T_U8 SHARPNESS_0_TAB[] = 
{
    //Sharpness -2
    0xa1, 0x10,
    0xa2, 0x00,
    END_FLAG, END_FLAG
};

static const T_U8 SHARPNESS_1_TAB[] = 
{
    //Sharpness -1
    0xa1, 0x14,
    0xa2, 0x02,
    END_FLAG, END_FLAG
};

static const T_U8 SHARPNESS_2_TAB[] = 
{
    //Sharpness default
    0xa1, 0x18,
    0xa2, 0x04,
    END_FLAG, END_FLAG
};

static const T_U8 SHARPNESS_3_TAB[] = 
{
    //Sharpness +1
    0xa1, 0x1c,
    0xa2, 0x08,
    END_FLAG, END_FLAG
};

static const T_U8 SHARPNESS_4_TAB[] = 
{
    //Sharpness +2
    0xa1, 0x1f,
    0xa2, 0x0c,
    END_FLAG, END_FLAG
};

static const T_U8 SHARPNESS_5_TAB[] = 
{
    //Sharpness auto
    0x9f, 0x0a,
    0xa0, 0x0f,
    0xa7, 0x0a,
    0xa8, 0x0f,
    END_FLAG, END_FLAG
};

static const T_U8 SHARPNESS_6_TAB[] = 
{
    END_FLAG, END_FLAG
};

/****************   Camera AWB Table   ****************/
static const T_U8 AWB_AUTO_TAB[] = 
{
    0x13, 0xff,
    END_FLAG, END_FLAG
};

static const T_U8 AWB_SUNNY_TAB[] = 
{
    /*0x13, 0xfb,
    0x05, 0x5e,
    0x06, 0x41,
    0x07, 0x54,
    0x08, 0x00,
    0x09, 0x00,*/
    END_FLAG, END_FLAG
};

static const T_U8 AWB_CLOUDY_TAB[] = 
{
    /*0x13, 0xfb,
    0x05, 0x65,
    0x06, 0x41,
    0x07, 0x4f,
    0x08, 0x00,
    0x09, 0x00,*/
    END_FLAG, END_FLAG
};

static const T_U8 AWB_OFFICE_TAB[] = 
{
    /*0x13, 0xfb,
    0x05, 0x52,
    0x06, 0x41,
    0x07, 0x66,
    0x08, 0x00,
    0x09, 0x00,*/
    END_FLAG, END_FLAG
};

static const T_U8 AWB_HOME_TAB[] = 
{
    /*0x13, 0xfb,
    0x05, 0x42,
    0x06, 0x3f,
    0x07, 0x71,
    0x08, 0x00,
    0x09, 0x00,*/
    END_FLAG, END_FLAG
};

/****************   Camera Effect Table   ****************/
static const T_U8 EFFECT_NORMAL_TAB[] = 
{
    //0xb6, 0x00,
    END_FLAG, END_FLAG
};

static const T_U8 EFFECT_SEPIA_TAB[] = 
{
    //0xb6, 0x18,
    //0xb9, 0x40,
    //0xba, 0xa0,
    END_FLAG, END_FLAG
};

static const T_U8 EFFECT_ANTIQUE_TAB[] = 
{
    //0xb6, 0x18,
    //0xb9, 0x40,
    //0xba, 0xa0,
    END_FLAG, END_FLAG
};

static const T_U8 EFFECT_BLUISH_TAB[] = 
{
    //0xb6, 0x18,
    //0xb9, 0xa0,
    //0xba, 0x40,
    END_FLAG, END_FLAG
};

static const T_U8 EFFECT_GREENISH_TAB[] = 
{
    //0xb6, 0x18,
    //0xb9, 0x60,
    //0xba, 0x60,
    END_FLAG, END_FLAG
};

static const T_U8 EFFECT_REDDISH_TAB[] = 
{
    //0xb6, 0x18,
    //0xb9, 0x80,
    //0xba, 0xc0,
    END_FLAG, END_FLAG
};

static const T_U8 EFFECT_NEGATIVE_TAB[] = 
{
    //0xb6, 0x40,
    END_FLAG, END_FLAG
};

static const T_U8 EFFECT_BW_TAB[] = 
{    
    //0xb6, 0x20,
    END_FLAG, END_FLAG
};

/****************   Camera night/day mode   ****************/
static const T_U8 DAY_MODE_TAB[] = 
{
    //0x14, 0xa0,
    //0x2e, 0x00,
    //0x2d, 0x00,
    END_FLAG, END_FLAG
};

static const T_U8 NIGHT_MODE_TAB[] = 
{
    //0x0e, 0xb8,
    //0x0f, 0x14,
    //0x14, 0xad,
    END_FLAG, END_FLAG
};
#endif
#endif
