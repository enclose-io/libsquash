/*
 * Copyright (c) 2017 Minqi Pan <pmq2001@gmail.com>
 *                    Shengyuan Liu <sounder.liu@gmail.com>
 *
 * This file is part of libsquash, distributed under the MIT License
 * For full terms see the included LICENSE file
 */

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <Windows.h>
#include <io.h>
#define ssize_t __int64
#endif

#include "enclose_io.h"

const uint8_t libsquash_fixture[4096] = { 104
,115,113,115,20,0,0,0,213,53,118,88,0,0,2,0,1,0,0,0,1,0,17,0,192,2,2,0,4,0,0,0,104,2
,0,0,0,0,0,0,114,6,0,0,0,0,0,0,106,6,0,0,0,0,0,0,255,255,255,255,255,255,255,255,218,3,0
,0,0,0,0,0,19,5,0,0,0,0,0,0,14,6,0,0,0,0,0,0,88,6,0,0,0,0,0,0,120,218,133,84
,75,111,227,54,16,62,71,191,98,144,75,19,212,49,108,55,217,118,219,83,30,219,194,192,166,27,192,105,123,48,124,24,75
,99,139,49,197,209,146,35,59,250,247,157,161,156,174,177,221,162,128,14,146,72,14,191,215,204,29,75,228,68,61,194,125,221
,197,178,134,53,55,107,23,182,69,241,41,192,116,10,15,84,82,179,166,8,179,201,244,221,8,16,82,231,74,87,81,222,167
,191,119,206,123,170,0,5,60,97,18,152,221,64,75,220,122,2,12,21,184,240,210,69,93,190,126,15,44,53,197,100,27,23
,50,134,39,18,61,108,91,242,23,118,254,187,244,134,224,162,228,166,225,224,123,216,5,62,4,192,4,31,252,213,221,87,64
,151,63,172,46,13,79,89,99,75,30,2,189,10,8,195,2,93,16,120,196,184,179,130,220,138,43,225,83,148,154,43,126,133
,123,84,16,85,68,63,130,68,138,132,55,160,63,254,181,237,137,91,26,41,118,221,239,34,107,157,219,245,26,147,67,168,92
,146,232,74,69,252,97,219,183,162,43,79,145,146,170,17,100,164,155,42,197,241,43,138,96,13,228,175,22,46,185,17,112,128
,71,14,21,246,144,183,185,141,83,57,236,210,163,126,74,110,54,187,234,9,227,21,251,74,129,215,13,119,170,74,141,27,247
,89,143,214,216,52,122,226,177,75,130,27,28,193,161,102,168,177,130,3,199,112,226,198,158,146,162,58,222,10,145,90,142,146
,47,82,150,82,71,34,104,40,100,189,81,143,54,24,180,200,94,65,144,253,141,74,194,118,43,227,146,67,160,82,156,194,62
,56,169,51,82,99,84,238,126,1,57,240,63,46,70,59,171,49,129,196,221,182,214,171,231,139,249,2,74,143,206,208,106,189
,150,67,114,107,231,157,244,176,225,120,82,104,188,188,94,45,111,86,240,92,187,4,250,216,202,198,69,205,142,232,225,252,89
,14,65,168,85,156,140,48,107,85,141,151,239,86,69,145,61,25,12,233,241,174,147,216,217,203,248,165,221,22,199,252,168,171
,139,197,105,196,44,94,70,78,35,60,41,62,114,137,198,239,44,215,80,87,71,131,205,163,193,211,226,1,133,206,190,14,126
,49,157,252,60,153,192,197,31,207,247,223,79,102,250,122,89,220,102,50,32,125,75,197,221,177,103,254,34,52,222,103,167,174
,20,15,154,180,58,157,205,110,138,223,57,92,109,80,208,15,125,225,40,21,215,239,139,39,138,45,73,68,225,152,206,254,199
,255,98,158,60,54,154,213,133,40,76,99,58,143,248,57,147,52,221,62,210,30,53,253,23,71,31,46,151,211,213,114,166,154
,21,34,82,124,59,159,118,44,19,119,154,137,147,52,39,116,21,156,255,169,60,184,83,143,40,70,142,46,53,102,216,96,252
,1,183,214,247,91,237,55,179,206,92,227,46,72,236,143,125,151,50,42,197,237,93,147,142,13,163,153,242,30,168,161,184,37
,208,86,226,176,61,90,212,176,38,170,11,206,98,184,137,220,104,65,189,41,57,233,178,89,227,115,200,193,70,159,24,42,82
,126,54,85,16,66,94,85,65,91,138,142,43,19,68,229,139,193,0,14,169,179,232,107,247,165,241,114,106,233,177,214,134,103
,60,96,165,195,4,230,243,255,26,1,95,162,116,235,233,85,17,70,109,255,33,235,54,101,106,210,59,49,244,58,70,74,193
,104,218,109,108,48,88,223,148,216,37,5,183,238,79,50,111,122,246,6,202,9,156,43,177,192,2,47,106,41,228,153,162,115
,83,101,120,235,146,183,57,220,125,115,85,251,95,103,107,56,170,178,156,254,184,250,66,167,212,35,169,214,206,7,19,79,39
,85,107,88,127,83,9,202,97,28,107,167,187,253,208,232,57,243,195,124,160,61,153,96,170,208,79,170,16,218,12,16,117,85
,47,109,176,202,33,107,72,50,223,10,50,53,195,82,50,239,6,149,217,234,141,139,191,1,189,36,47,247,55,1,120,218,99
,98,88,194,200,192,192,200,240,69,49,40,2,200,64,1,207,152,25,24,152,25,222,130,229,179,140,202,34,128,92,6,144,26
,118,32,206,47,202,76,203,204,73,133,73,151,3,165,89,160,210,108,64,156,147,90,150,154,99,8,147,109,0,202,178,162,203
,26,49,65,173,14,5,202,178,161,89,11,50,11,166,155,205,184,44,130,29,170,27,228,132,226,28,99,152,212,9,160,86,14
,20,41,184,157,215,128,82,156,40,82,70,140,80,169,169,166,101,17,76,80,203,64,116,38,16,139,128,217,16,7,57,107,5
,69,240,32,57,232,21,80,191,58,19,72,230,47,88,254,5,80,158,27,73,191,60,67,26,3,23,3,66,94,94,37,40,130
,23,73,158,153,161,9,44,15,51,127,33,80,191,0,146,249,130,64,223,91,32,121,184,79,183,44,66,8,234,116,105,32,214
,211,211,135,34,3,32,52,113,40,206,207,77,45,201,200,204,75,55,209,135,89,249,24,104,164,32,146,149,10,64,43,249,145
,156,180,15,40,207,15,149,7,133,134,1,195,124,6,62,36,249,0,160,60,31,146,188,20,195,25,176,147,145,157,36,12,117
,18,200,30,12,151,192,12,170,6,134,45,23,212,32,80,148,135,48,60,6,135,45,76,126,43,80,94,4,42,15,138,100,51
,6,19,70,81,32,13,0,163,34,81,85,232,0,120,218,69,80,219,9,194,48,20,189,55,245,85,20,20,23,208,1,68,90
,237,191,254,8,126,184,130,72,75,99,13,164,137,218,42,136,43,184,129,123,248,235,12,78,224,2,238,160,183,105,107,19,14
,57,57,247,220,71,210,128,124,89,132,161,57,235,32,249,153,75,119,6,88,221,38,107,96,213,109,122,37,206,160,1,250,40
,182,66,242,59,212,140,144,72,247,65,158,156,78,94,100,200,233,180,104,2,157,12,8,36,54,97,17,93,246,169,240,85,25
,235,19,110,152,77,208,130,68,199,60,221,9,21,97,17,236,17,164,73,172,129,31,232,83,250,68,164,249,218,160,116,200,55
,177,14,79,146,39,101,165,46,225,77,102,36,251,222,87,86,33,183,9,35,35,247,96,236,208,246,230,255,62,222,10,153,121
,239,56,16,234,139,22,241,58,204,99,161,14,98,192,90,164,219,213,76,30,43,10,150,195,101,63,17,232,152,50,163,15,160
,41,19,138,163,179,100,118,201,221,31,92,58,57,44,15,0,120,218,75,96,128,128,42,102,8,13,0,9,245,0,222,253,5
,0,0,0,0,0,0,64,0,120,218,99,96,128,128,55,80,90,1,74,219,67,233,88,40,93,13,165,103,67,233,109,80,250
,34,148,246,96,130,208,58,140,16,154,7,74,251,64,233,255,80,250,62,148,206,129,210,251,161,116,15,148,150,135,154,147,1
,165,1,224,152,9,60,22,6,0,0,0,0,0,0,8,128,245,1,0,0,20,0,0,0,96,6,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0
};

static void expect(short condition, const char *reason)
{
	if (condition) {
		fprintf(stderr, ".");
	}
	else {
		fprintf(stderr, "x");
		fprintf(stderr, "\nFAILED: %s\n", reason);
		exit(1);
	}
	fflush(stderr);
}

int main() {
	int ret;

	squash_start();
	enclose_io_fs = (sqfs *)calloc(sizeof(sqfs), 1);
	sqfs_open_image(enclose_io_fs, libsquash_fixture, 0);

#ifdef _WIN32
	ret = _wmkdir(L"X:\\__enclose_io_memfs__\\jj");
	expect(0 == ret, "");
	expect(SetCurrentDirectoryW(L"J:\\__enclose_io_memfs__\\jj"), "");
	ret = _wmkdir(L"dd");
	expect(0 == ret, "");
#else
	ret = mkdir("/__enclose_io_memfs__/jj");
	expect(0 == ret, "";
	ret = chdir("/__enclose_io_memfs__/jj");
	expect(0 == ret, "";
	ret = mkdir("dd");
	expect(0 == ret, "";
#endif
	return 0;
}
