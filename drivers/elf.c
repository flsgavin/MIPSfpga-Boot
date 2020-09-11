#include "elf.h"
#include <stddef.h>

static void *memSet(void *s, int c, size_t n)
{
  if (NULL == s || n < 0)
    return NULL;
  char * tmpS = (char *)s;
  while(n-- > 0)
    *tmpS++ = c;
    return s; 
}

static void *memCpy(void *dest, const void *src, size_t n)
{
  if (NULL == dest || NULL == src || n < 0)
    return NULL;
  char *tempDest = (char *)dest;
  char *tempSrc = (char *)src;
 
  while (n-- > 0)
    *tempDest++ = *tempSrc++;
  return dest;  
}

  int load_elf(const uint8_t *elf, const uint32_t elf_size) {
  // sanity checks
  if(elf_size <= sizeof(Elf32_Ehdr))
    return 1;                   /* too small */

  const Elf32_Ehdr *eh = (const Elf32_Ehdr *)elf;
  if(!IS_ELF32(*eh))
    return 2;                   /* not a elf32 file */

  const Elf32_Phdr *ph = (const Elf32_Phdr *)(elf + eh->e_phoff);
  if(elf_size < eh->e_phoff + eh->e_phnum*sizeof(*ph))
    return 3;                   /* internal damaged */

  //Load elf in RAM to the specified physical address

  ???
  
  return 0;
}