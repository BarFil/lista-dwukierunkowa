#include<stdio.h>
#include<stdlib.h>
#include "doubly_linked_list.h"

struct doubly_linked_list_t* dll_create()
{
  struct doubly_linked_list_t* lista = (struct doubly_linked_list_t*)malloc(sizeof(struct doubly_linked_list_t));
  if(lista==NULL)return NULL;
  lista->tail=NULL;
  lista->head=NULL;
  return lista;
}


int dll_push_back(struct doubly_linked_list_t* dll, int value)
{
  if(dll==NULL)return 1;
  if((dll->head==NULL && dll->tail!=NULL) || (dll->head!=NULL && dll->tail==NULL))return 1;
  if(dll->head == NULL && dll->tail == NULL)
  {
    struct node_t *temp=(struct node_t*)malloc(sizeof(struct node_t));
    if(temp==NULL)return 2;
    temp->data=value;
    temp->next=NULL;
    temp->prev=NULL;
    dll->head=temp;
    dll->tail=temp;
  }
  else
  {
    struct node_t *temp=(struct node_t*)malloc(sizeof(struct node_t));
    if(temp==NULL)return 2;
    temp->data=value;
    temp->next=NULL;
    temp->prev=dll->tail;
    dll->tail->next=temp;
    dll->tail=temp;
  }
return 0;
}


int dll_push_front(struct doubly_linked_list_t* dll, int value)
{
if(dll==NULL)return 1;
  if((dll->head==NULL && dll->tail!=NULL) || (dll->head!=NULL && dll->tail==NULL))return 1;
  if(dll->head == NULL && dll->tail == NULL)
  {
    struct node_t *temp=(struct node_t*)malloc(sizeof(struct node_t));
    if(temp==NULL)return 2;
    temp->data=value;
    temp->next=NULL;
    temp->prev=NULL;
    dll->head=temp;
    dll->tail=temp;
  }
  else
  {
    struct node_t *temp=(struct node_t*)malloc(sizeof(struct node_t));
    if(temp==NULL)return 2;
    temp->data=value;
    temp->next=dll->head;
    temp->prev=NULL;
    dll->head->prev=temp;
    dll->head=temp;
  }
return 0;
}


int dll_pop_front(struct doubly_linked_list_t* dll, int *err_code)
{
  if(dll==NULL)
  {
    if(err_code!=NULL)*err_code=1;
    return 0;
  }

  if((dll->head==NULL && dll->tail!=NULL) || (dll->head!=NULL && dll->tail==NULL))  
  {
    if(err_code!=NULL)*err_code=1;
    return 0;
  }

  if(dll->head==NULL && dll->tail==NULL)
  {
    if(err_code!=NULL)*err_code=1;
    return 0;
  }

  int value;
  if(dll->head ==  dll->tail )
  {
    value=dll->head->data;
    free(dll->head);
    dll->head=NULL;
    dll->tail=NULL;
  }
  else
  {
    value=dll->head->data;
    struct node_t* temp=dll->head;
    dll->head=dll->head->next;
    dll->head->prev=NULL;
    free(temp);
  }

if(err_code!=NULL)*err_code=0;
return value;
}


int dll_pop_back(struct doubly_linked_list_t* dll, int *err_code)
{
  if(dll==NULL)
  {
    if(err_code!=NULL)*err_code=1;
    return 0;
  }

  if((dll->head==NULL && dll->tail!=NULL) || (dll->head!=NULL && dll->tail==NULL))  
  {
    if(err_code!=NULL)*err_code=1;
    return 0;
  }

  int value;
  if(dll->head==NULL && dll->tail==NULL)
  {
    if(err_code!=NULL)*err_code=1;
    return 0;
  }
  if(dll->head == dll->tail )
  {
    value=dll->tail->data;
    free(dll->tail);
    dll->head=NULL;
    dll->tail=NULL;
  }
  else
  {
    value=dll->tail->data;
    struct node_t* temp=dll->tail;
    dll->tail=dll->tail->prev;
    dll->tail->next=NULL;
    free(temp);
  }

if(err_code!=NULL)*err_code=0;
return value;
}


int dll_back(const struct doubly_linked_list_t* dll, int *err_code)
{
  if(dll==NULL)
  {
    if(err_code!=NULL)*err_code=1;
    return 0;
  }

  if((dll->head==NULL && dll->tail!=NULL) || (dll->head!=NULL && dll->tail==NULL))  
  {
    if(err_code!=NULL)*err_code=1;
    return 0;
  }

  if(dll->head==NULL && dll->tail==NULL)
  {
    if(err_code!=NULL)*err_code=1;
    return 0;
  }

  int value;
  value=dll->tail->data;

if(err_code!=NULL)*err_code=0;
return value;
}


int dll_front(const struct doubly_linked_list_t* dll, int *err_code)
{
  if(dll==NULL)
  {
    if(err_code!=NULL)*err_code=1;
    return 0;
  }

  if((dll->head==NULL && dll->tail!=NULL) || (dll->head!=NULL && dll->tail==NULL))  
  {
    if(err_code!=NULL)*err_code=1;
    return 0;
  }

  if(dll->head==NULL && dll->tail==NULL)
  {
    if(err_code!=NULL)*err_code=1;
    return 0;
  }

  int value;
  value=dll->head->data;

if(err_code!=NULL)*err_code=0;
return value;
}


struct node_t* dll_begin(struct doubly_linked_list_t* dll)
{
  if(dll==NULL)
  {
    return NULL;
  }

  if((dll->head==NULL && dll->tail!=NULL) || (dll->head!=NULL && dll->tail==NULL))  
  {
    return NULL;
  }

  return dll->head;
}


struct node_t* dll_end(struct doubly_linked_list_t* dll)
{
  if(dll==NULL)
  {
    return NULL;
  }

  if((dll->head==NULL && dll->tail!=NULL) || (dll->head!=NULL && dll->tail==NULL))  
  {
    return NULL;
  }

  return dll->tail;
}


int dll_size(const struct doubly_linked_list_t* dll)
{
if(dll==NULL)
{
  return -1;
}

if((dll->head==NULL && dll->tail!=NULL) || (dll->head!=NULL && dll->tail==NULL))  
{
  return -1;
}

if(dll->head==NULL && dll->tail==NULL)return 0;

struct node_t *temp = dll->head;
int size=1;
while(temp->next!=NULL)
{
  size++;
  temp=temp->next;
}
return size;
}


int dll_is_empty(const struct doubly_linked_list_t* dll)
{
  if(dll==NULL)
  {
    return -1;
  }

  if((dll->head==NULL && dll->tail!=NULL) || (dll->head!=NULL && dll->tail==NULL))  
  {
    return -1;
  }
  if(dll_size(dll)==0)return 1;
  return 0;
}


int dll_at(const struct doubly_linked_list_t* dll, unsigned int index, int *err_code)
{
  if(dll==NULL || (int)index >= dll_size(dll))
  {
    if(err_code!=NULL)*err_code=1;
    return -1;
  }

  if((dll->head==NULL && dll->tail!=NULL) || (dll->head!=NULL && dll->tail==NULL))  
  {
    if(err_code!=NULL)*err_code=1;
    return -1;
  }

  if(dll->head==NULL && dll->tail==NULL)
  {
    if(err_code!=NULL)*err_code=1;
    return -1;    
  }
  
  if(index==0)
  {
    if(err_code!=NULL)*err_code=0;
    return dll->head->data;
  }

  struct node_t *temp = dll->head;
  unsigned int numer=1;
  while(temp->next!=NULL)
  {
    if(numer==index)break;
    numer++;
    temp=temp->next;
  }
  if(err_code!=NULL)*err_code=0;
  return temp->next->data;
}


int dll_insert(struct doubly_linked_list_t* dll, unsigned int index, int value)
{
  if(dll==NULL || index > (unsigned int)dll_size(dll))
  {
    return 1;
  }

  if((dll->head==NULL && dll->tail!=NULL) || (dll->head!=NULL && dll->tail==NULL))  
  {
    return 1;
  }
 
  
  if(index==0)
  {
    if( dll_push_front(dll, value) == 2 )return 2;
    return 0;
  }
  if(index == (unsigned int)dll_size(dll))
  {
    if( dll_push_back(dll, value)==2 )return 2;
    return 0;
  }

  struct node_t *temp = dll->head;
  unsigned int numer=0;
  while(temp->next!=NULL)
  {
    numer++;
    if(numer==index)break;
    temp=temp->next;
  }
  
  struct node_t *new_node=(struct node_t*)malloc(sizeof(struct node_t));
  if(new_node==NULL)return 2;
  
  new_node->data=value;
  new_node->prev=temp;
  new_node->next=temp->next;
  temp->next->prev=new_node;
  temp->next=new_node;


  return 0;
}


int dll_remove(struct doubly_linked_list_t* dll, unsigned int index, int *err_code)
{
  if(dll==NULL || index >= (unsigned int) dll_size(dll))
  {
    if(err_code!=NULL)*err_code=1;
    return 1;
  }

  if((dll->head==NULL && dll->tail!=NULL) || (dll->head!=NULL && dll->tail==NULL))  
  {
    if(err_code!=NULL)*err_code=1;
    return 1;
  }

  if(dll->head==NULL && dll->tail==NULL)
  {
    if(err_code!=NULL)*err_code=1;
    return 1;
  }
 
  if(index==0)
  {
    if(err_code!=NULL)*err_code=0;
    return dll_pop_front(dll, err_code);
  }

  if(index == (unsigned int)dll_size(dll) -1)
  {
    if(err_code!=NULL)*err_code=0;
    return dll_pop_back(dll, err_code);
  }

  struct node_t *temp = dll->head;
  unsigned int numer=0;
  while(temp->next!=NULL)
  {
    if(numer==index-1)break;
    numer++;
    temp=temp->next;
  }
  int value;
  value=temp->next->data;
  temp->next=temp->next->next;
  free(temp->next->prev);
  temp->next->prev=temp;

  if(err_code!=NULL)*err_code=0;
  return value;
}



void dll_clear(struct doubly_linked_list_t* dll)
{
  if(dll==NULL)
  {
    return;
  }

  if((dll->head==NULL && dll->tail!=NULL) || (dll->head!=NULL && dll->tail==NULL))  
  {
    return;
  }
  if(dll->tail==NULL && dll->head==NULL)
  {
    return;
  }

  struct node_t* temp=dll->head;
  while(temp)
  {
    dll->head=temp->next;
    free(temp);
    temp=temp->next;
  }
  dll->tail=NULL;
}


void dll_display(const struct doubly_linked_list_t* dll)
{
  if(dll==NULL)
  {
    return;
  }

  if((dll->head==NULL && dll->tail!=NULL) || (dll->head!=NULL && dll->tail==NULL))  
  {
    return;
  }
  if(dll->tail==NULL && dll->head==NULL)
  {
    return;
  }

  struct node_t* temp=dll->head;
  while(temp)
  {
   printf("%d ",temp->data);
   temp=temp->next;
  }
  printf("\n");
}


void dll_display_reverse(const struct doubly_linked_list_t* dll)
{
    if(dll==NULL)
  {
    return;
  }

  if((dll->head==NULL && dll->tail!=NULL) || (dll->head!=NULL && dll->tail==NULL))  
  {
    return;
  }
  if(dll->tail==NULL && dll->head==NULL)
  {
    return;
  }
  struct node_t* temp=dll->tail;
  while(temp)
  {
   printf("%d ",temp->data);
   temp=temp->prev;
  }
  printf("\n");
}
