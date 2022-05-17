#include <stdio.h>
#include<stdlib.h>

#include "doubly_linked_list.h"


int main(void) {
  int wybor=1;
  struct doubly_linked_list_t* lista = dll_create();
  if(lista == NULL)
  {
    printf("Failed to allocate memory\n");
    return 8;
  }

  while(wybor!=0)
  {
    printf("Co chcesz zrobić: ");
    if( scanf("%d",&wybor) != 1)
    {
      dll_clear(lista);
      free(lista);
      printf("Incorrect input\n");
      return 1;
    }

    if(wybor==0)
    {
      dll_clear(lista);
      free(lista);
      return 0;
    }

    else if(wybor==1)
    {
      int x;
      printf("Podaj wartość: ");
      if( scanf("%d",&x)!=1 )
      {
        printf("Incorrect input\n");
        dll_clear(lista);
        free(lista);
        return 1;
      }
      if( dll_push_back(lista, x) == 2)
      {
        printf("Failed to allocate memory\n");
        dll_clear(lista);
        free(lista);
        return 8;
      }
    }

    else if(wybor==2)
    {
      if(lista->head==NULL)
      {
        printf("List is empty\n");
      }
      else
      {
        printf("%d\n",dll_pop_back(lista, NULL));
      }
    }

    else if(wybor==3)
    {
      int y;
      printf("Podaj wartość: ");
      if( scanf("%d",&y)!=1 )
      {
        printf("Incorrect input\n");
        dll_clear(lista);
        free(lista);
        return 1;
      }
      if( dll_push_front(lista, y) == 2)
      {
        printf("Failed to allocate memory\n");
        dll_clear(lista);
        free(lista);
        return 8;
      }
    }

    else if(wybor==4)
    {
      if(lista->head==NULL)
      {
        printf("List is empty\n");
      }
      else
      {
        printf("%d\n",dll_pop_front(lista, NULL));
      }
    }

    else if(wybor==5)
    {
      int z;
      unsigned int index;
      printf("Podaj wartość: ");
      if( scanf("%d",&z)!=1 )
      {
        printf("Incorrect input\n");
        dll_clear(lista);
        free(lista);
        return 1;
      }
      printf("Podaj indeks: ");
      if( scanf("%u",&index)!=1 )
      {
        printf("Incorrect input\n");
        dll_clear(lista);
        free(lista);
        return 1;
      }
      if( (int)index>dll_size(lista) )
      {
        printf("Index out of range\n");
      }
      else
      {
        if( dll_insert(lista, index, z) == 2)
        {
          printf("Failed to allocate memory\n");
          dll_clear(lista);
          free(lista);
          return 8;
        }
      }
    }

    else if(wybor==6)
    {
       if(lista->head==NULL)
      {
        printf("List is empty\n");
      }
      else
      {
        unsigned int index;
        printf("Podaj indeks: ");
        if( scanf("%u",&index)!=1 )
        {
          printf("Incorrect input\n");
          dll_clear(lista);
          free(lista);
          return 1;
        }
        if( (int)index>dll_size(lista) )
        {
          printf("Index out of range\n");
        }
        else
        {
          printf("%d\n",dll_remove(lista, index, NULL) );
        }
        
      }
    }

    else if(wybor==7)
    {
       if(lista->head==NULL)
      {
        printf("List is empty\n");
      }
      else
      {
        printf("%d\n",dll_back(lista, NULL) );
      }
    }

    else if(wybor==8)
    {
      if(lista->head==NULL)
      {
        printf("List is empty\n");
      }
      else
      {
        printf("%d\n",dll_front(lista, NULL) );
      }
    }

    else if(wybor==9)
    {
      printf("%d\n",dll_is_empty(lista));
    }

    else if(wybor==10)
    {
      printf("%d\n",dll_size(lista));
    }

    else if(wybor==11)
    {
      dll_clear(lista);
    }

    else if(wybor==12)
    {
      if(lista->head==NULL)
      {
        printf("List is empty\n");
      }
      else
      {
        unsigned int index;
        printf("Podaj indeks: ");
        if( scanf("%u",&index)!=1 )
        {
          printf("Incorrect input\n");
          dll_clear(lista);
          free(lista);
          return 1;
        }
        if( (int)index>dll_size(lista) )
        {
          printf("Index out of range\n");
        }
        else
        {
          printf("%d\n",dll_at(lista, index, NULL) );
        }
      }
    }

    else if(wybor==13)
    {
      if(lista->head==NULL)
      {
        printf("List is empty\n");
      }
      else
      {
        dll_display(lista);
      }
    }

    else if(wybor==14)
    {
      if(lista->head==NULL)
      {
        printf("List is empty\n");
      }
      else
      {
        dll_display_reverse(lista);
      }
    }

    else
    {
      printf("Incorrect input data\n");
    }
  }
  dll_clear(lista);
  free(lista);
  return 0;
}