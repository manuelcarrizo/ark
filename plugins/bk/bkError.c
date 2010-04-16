/******************************* LICENSE **************************************
* Any code in this file may be redistributed or modified under the terms of
* the GNU General Public License as published by the Free Software
* Foundation; version 2 of the license.
****************************** END LICENSE ***********************************/

/******************************************************************************
* Author:
* Andrew Smith, http://littlesvr.ca/misc/contactandrew.php
*
* Copyright 2005-2007 Andrew Smith <andrew-smith@mail.ru>
*
* Contributors:
*
******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>

#include "bkInternal.h"
#include "bkError.h"

struct MessageStruct {
    int number;
    const char* text;
};

const struct MessageStruct messageStructs[] = {
    { BKERROR_READ_GENERIC, BKERROR_READ_GENERIC_TEXT },
    { BKERROR_DIR_NOT_FOUND_ON_IMAGE, BKERROR_DIR_NOT_FOUND_ON_IMAGE_TEXT },
    { BKERROR_MAX_NAME_LENGTH_EXCEEDED, BKERROR_MAX_NAME_LENGTH_EXCEEDED_TEXT },
    { BKERROR_STAT_FAILED, BKERROR_STAT_FAILED_TEXT },
    { BKERROR_TARGET_NOT_A_DIR, BKERROR_TARGET_NOT_A_DIR_TEXT },
    { BKERROR_OUT_OF_MEMORY, BKERROR_OUT_OF_MEMORY_TEXT },
    { BKERROR_OPENDIR_FAILED, BKERROR_OPENDIR_FAILED_TEXT },
    { BKERROR_EXOTIC, BKERROR_EXOTIC_TEXT },
    { BKERROR_FIXME, BKERROR_FIXME_TEXT },
    { BKERROR_FILE_NOT_FOUND_ON_IMAGE, BKERROR_FILE_NOT_FOUND_ON_IMAGE_TEXT },
    { BKERROR_MKDIR_FAILED, BKERROR_MKDIR_FAILED_TEXT },
    { BKERROR_OPEN_WRITE_FAILED, BKERROR_OPEN_WRITE_FAILED_TEXT },
    { BKERROR_WRITE_GENERIC, BKERROR_WRITE_GENERIC_TEXT },
    { BKERROR_MANGLE_TOO_MANY_COL, BKERROR_MANGLE_TOO_MANY_COL_TEXT },
    { BKERROR_MISFORMED_PATH, BKERROR_MISFORMED_PATH_TEXT },
    { BKERROR_INVALID_UCS2, BKERROR_INVALID_UCS2_TEXT },
    { BKERROR_UNKNOWN_FILENAME_TYPE, BKERROR_UNKNOWN_FILENAME_TYPE_TEXT },
    { BKERROR_RR_FILENAME_MISSING, BKERROR_RR_FILENAME_MISSING_TEXT },
    { BKERROR_VD_NOT_PRIMARY, BKERROR_VD_NOT_PRIMARY_TEXT },
    { BKERROR_SANITY, BKERROR_SANITY_TEXT },
    { BKERROR_OPEN_READ_FAILED, BKERROR_OPEN_READ_FAILED_TEXT },
    { BKERROR_DIRNAME_NEED_TRAILING_SLASH, BKERROR_DIRNAME_NEED_TRAILING_SLASH_TEXT },
    { BKERROR_EXTRACT_ROOT, BKERROR_EXTRACT_ROOT_TEXT },
    { BKERROR_DELETE_ROOT, BKERROR_DELETE_ROOT_TEXT },
    { BKERROR_DUPLICATE_ADD, BKERROR_DUPLICATE_ADD_TEXT },
    { BKERROR_DUPLICATE_EXTRACT, BKERROR_DUPLICATE_EXTRACT_TEXT },
    { BKERROR_NO_SPECIAL_FILES, BKERROR_NO_SPECIAL_FILES_TEXT },
    { BKERROR_NO_POSIX_PRESENT, BKERROR_NO_POSIX_PRESENT_TEXT },
    { BKERROR_EXTRACT_ABSENT_BOOT_RECORD, BKERROR_EXTRACT_ABSENT_BOOT_RECORD_TEXT },
    { BKERROR_EXTRACT_UNKNOWN_BOOT_MEDIA, BKERROR_EXTRACT_UNKNOWN_BOOT_MEDIA_TEXT },
    { BKERROR_ADD_UNKNOWN_BOOT_MEDIA, BKERROR_ADD_UNKNOWN_BOOT_MEDIA_TEXT },
    { BKERROR_ADD_BOOT_RECORD_WRONG_SIZE, BKERROR_ADD_BOOT_RECORD_WRONG_SIZE_TEXT },
    { BKERROR_WRITE_BOOT_FILE_4, BKERROR_WRITE_BOOT_FILE_4_TEXT },
    { BKERROR_DUPLICATE_CREATE_DIR, BKERROR_DUPLICATE_CREATE_DIR_TEXT },
    { BKERROR_NAME_INVALID_CHAR, BKERROR_NAME_INVALID_CHAR_TEXT },
    { BKERROR_BLANK_NAME, BKERROR_BLANK_NAME_TEXT },
    { BKERROR_ADD_FILE_TOO_BIG, BKERROR_ADD_FILE_TOO_BIG_TEXT },
    { BKERROR_SAVE_OVERWRITE, BKERROR_SAVE_OVERWRITE_TEXT },
    { BKERROR_OPER_CANCELED_BY_USER, BKERROR_OPER_CANCELED_BY_USER_TEXT },
    { BKERROR_WRONG_EXTRACT_FILE, BKERROR_WRONG_EXTRACT_FILE_TEXT },
    { BKERROR_WRITE_CACHE_OVERFLOWED, BKERROR_WRITE_CACHE_OVERFLOWED_TEXT },
    { BKERROR_CREATE_SYMLINK_FAILED, BKERROR_CREATE_SYMLINK_FAILED_TEXT },
    { BKERROR_SYMLINK_TARGET_TOO_LONG, BKERROR_SYMLINK_TARGET_TOO_LONG_TEXT },
    { BKERROR_HARD_LINK_CALL_PARAMS, BKERROR_HARD_LINK_CALL_PARAMS_TEXT },
    { BKERROR_NAME_INVALID, BKERROR_NAME_INVALID_TEXT },
    { BKERROR_DUPLICATE_RENAME, BKERROR_DUPLICATE_RENAME_TEXT },
    { BKERROR_GET_PERM_BAD_PARAM, BKERROR_GET_PERM_BAD_PARAM_TEXT },

    { BKWARNING_OPER_PARTLY_FAILED, BKWARNING_OPER_PARTLY_FAILED_TEXT },

    { BKERROR_END, BKERROR_END_TEXT }
};

const char* bk_get_error_string(int errorId)
{
    int count;

    for (count = 0; messageStructs[count].number != BKERROR_END; count++) {
        if (messageStructs[count].number == errorId)
            break;
    }

    if (messageStructs[count].number == BKERROR_END)
        printf("unknown error %d used\n", errorId);

    return messageStructs[count].text;
}