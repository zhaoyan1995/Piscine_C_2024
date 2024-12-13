The difference between strncpy and strlcpy is :
strncpy can not add automatically '\0' at the end of the destination buffer (when size of source buffer > destination buffer) it can only include '\0' from source buffer if size of source buffer < destination buffer

But strlcpy can automatically add '\0' (IF destination buffer or size in parameter > 0) even source buffer > destination buffer , in addition, strlcpy can return the length of source buffer (the length of source string). 
