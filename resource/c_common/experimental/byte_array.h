/******************************************************************
 *
 * Copyright 2015 Samsung Electronics All Rights Reserved.
 *
 *
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      LICENSE-2.0" target="_blank">http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *

 ******************************************************************/


#ifndef _BYTE_ARRAY_H_
#define _BYTE_ARRAY_H_

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include <string.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * @struct ByteArray_t
 *
 * General purpose byte array structure.
 *
 * Contains pointer to array of bytes and it's length.
 */

typedef struct ByteArray
{
    uint8_t *data;    /**< Pointer to the byte array */
    size_t len;      /**< Data size */
} ByteArray_t;


/**@def BYTE_ARRAY_INITIALIZER
 *
 * Initializes of existing byte array pointer to \a NULL.
 */
#undef BYTE_ARRAY_INITIALIZER
#define BYTE_ARRAY_INITIALIZER {NULL, 0}

/**@def INIT_BYTE_ARRAY(array)
 *
 * Initializes of existing byte array \a array.
 *
 * @param array ByteArray_t
 */
#undef INIT_BYTE_ARRAY
#define INIT_BYTE_ARRAY(array) do{  \
        (array).data = NULL;        \
        (array).len = 0;            \
    }while(0)

/**@def DEINIT_BYTE_ARRAY(array)
 *
 * Deinitializes of existing byte array \a array.
 *
 * @param array ByteArray_t
 */
#undef DEINIT_BYTE_ARRAY
#define DEINIT_BYTE_ARRAY(array) do{  \
        OICFree((array).data);       \
        (array).data = NULL;        \
        (array).len = 0;            \
    }while(0)

/**@def PRINT_BYTE_ARRAY(msg, array)
 *
 * Prints out byte array \a array in hex representation with message \a msg.
 *
 * @param msg string of characters
 * @param array byte array
 */
#undef PRINT_BYTE_ARRAY
#define PRINT_BYTE_ARRAY(msg, array) do{                \
        size_t i;                                       \
        printf("%10s", msg);                            \
        for( i=0; i< (array).len; i++) {                \
            if( (i!=0) && ((i%16)==0) ) putchar('\n');  \
            printf("%02X ", (array).data[i]);        \
        }                                               \
        putchar('\n');                                  \
    }while(0)

/**@def INC_BYTE_ARRAY_PTR(array, size)
 *
 * Increments byte array pointer \a array by \a size.
 *
 * @param array byte array pointer
 * @param size number of positions
 */
#undef INC_BYTE_ARRAY_PTR
#define INC_BYTE_ARRAY_PTR(array, size) do{      \
        (array)->data += size;                   \
        (array)->len -= size;                    \
    }while(0)

/**@def INC_BYTE_ARRAY(array, size)
 *
 * Increments byte array \a array by \a size.
 *
 * @param array byte array
 * @param size number of positions
 */
#undef INC_BYTE_ARRAY
#define INC_BYTE_ARRAY(array, size) do{      \
        (array).data += size;                \
        (array).len -= size;                 \
    }while(0)

#ifdef __cplusplus
}
#endif //__cplusplus

#endif // _BYTE_ARRAY_H_
