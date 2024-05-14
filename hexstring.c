#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PON_MODE_STRING_LENGTH 10
#define PON_REGISTRATION_ID_MAX_LENGTH 36

#define INCREMENT_PTR(ptr, num) \
   int index = 0;               \
   while (index++ < num)        \
   {                            \
      *ptr++;                   \
   }

#define DECREMENT_PTR(ptr, num) \
   int index2 = 0;              \
   while (index2++ < num)       \
   {                            \
      *ptr--;                   \
   }

static void help_insert_substring(char *input_string, char *output_string, char *substring, int char_steps)
{
   int char_count = 0;
   int substring_length = strlen(substring); // 3

   strcpy(output_string, substring); //" 0x"
   INCREMENT_PTR(output_string, substring_length);

   while (*input_string)
   {

      *output_string++ = *input_string++;
      ++char_count;

      if (char_count == char_steps)
      {

         strcat(output_string, substring);
         INCREMENT_PTR(output_string, substring_length);
         char_count = 0;
      }
   }

   DECREMENT_PTR(output_string, substring_length);
   *output_string = '\0';
}

static inline int char_is_valid(char c)
{
   return c >= 0x20 && c < 0x7f;
}

void insert_substring(char *in_hex, char *out_hex, size_t size) // size of out_hex
{
   // in : AABBCC
   //out : " 0xaa 0xaa"
   int pos = 0;
   char buf[3] = {0};

   for (int i = 0; i < strlen(in_hex); i += 2)
   {
      strncpy(buf, &in_hex[i],2);
      pos += snprintf((char *)out_hex + pos, size - pos ," 0x%s", buf);
   }

   out_hex[pos] ='\0';
}

void convert_string_to_hex(const char *str, char *hex, size_t size)
{
   int i, len = strlen(str);
   unsigned pos = 0;

   for (i = 0; i < len && pos < size - 2; i++)
   {
      pos += snprintf((char *)hex + pos, size - pos, "%02X", str[i]);
   }

   hex[pos] = '\0'; // hex'\0'
}

int main()
{
   system("clear");
   int start = 0;
   char str[37] = {0};
   char hex[256] = {0};
   char revice[37] = {0};
   char type[16] = {0}; // "gpon", "xgspon"
   char value[256] = {0};
   char sub_hex[256] ={0};

   strcpy(type, "xgspon");
   strncpy(revice, "test", 36);
   memset(str, ' ', 36);

   // check type
   if (!strcmp(type, "gpon"))
   {
      printf("Gpon \n");
      if (strlen(value) < 36)
      {
         start = 36 - strlen(revice);
      }
      strncpy(&str[start], revice, strlen(revice));
   }
   else
   {
      printf("xgspon \n");
      if (strlen(revice) < 10)
      {
         start = 10 - strlen(revice);
      }
      strncpy(&str[start], revice, strlen(revice));
   }

   //printf(" str = |%s|\n", str);

   convert_string_to_hex("testtttttt", hex, sizeof(hex));
   printf("hex = \n|%s|\n", hex);

   insert_substring(hex, sub_hex, sizeof(sub_hex));
   printf("sub_hex = \n|%s|\n", sub_hex);

   return (0);
}