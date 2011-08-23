#include <string.h>

#undef offsetof
#ifdef __compiler_offsetof
#define offsetof(TYPE,MEMBER) __compiler_offsetof(TYPE,MEMBER)
#else
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif

/**
 *** container_of - cast a member of a structure out to the containing structure
 *** @ptr:        the pointer to the member.
 *** @type:       the type of the container struct this is embedded in.
 *** @member:     the name of the member within the struct.
 ***
 ***/

#define container_of(ptr, type, member) ({                      \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})


#define WORDSIZE 512

struct list_head 
{
	struct list_head *next, *prev;	
};

struct word_st
{
	char *word;
	struct list_head list_node;
	int count;
};

void INIT_LIST_HEAD(struct list_head *list)
{
        list->next = list;
        list->prev = list;
}

void __list_add(struct list_head *new,
                              struct list_head *prev,
                              struct list_head *next)
{
        next->prev = new;
        new->next = next;
        new->prev = prev;
        prev->next = new;
}

void list_add(struct list_head *new, struct list_head *head)
{
        __list_add(new, head, head->next);
}

void get_list_tail(struct list_head *head, struct list_head *tail)
{
	struct list_head *temp = head;
	for(; head->next != head; head = head->next);
	*tail = *head;
	head = temp;
}

struct word_st *init_word_st(char *str, struct list_head *head)
{
	struct word_st *ws;
	ws->word = str;
	ws->count = strlen(str);	
	list_add(&(ws->list_node), head);	
	return ws;
}
