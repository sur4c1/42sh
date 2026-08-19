NAME		= libft.a

SDIR		= srcs
ODIR		= objs
IDIR		= incs

AR			= ar rcs
RM			= rm -rf
MKDIR		= mkdir -p
CFLAGS		= -Wall -Wextra -Werror
CFLAGS		+= -I$(IDIR)

OBJS = $(addprefix $(ODIR)/, $(addsuffix .o, $(SRCS)))

.DEFAULT_GOAL := all

include objects.mk

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(ODIR)

fclean: clean
	$(RM) $(NAME) objects.mk

$(LDIR)/libft/libft.a:
	$(MAKE) -C $(LDIR)/libft

$(ODIR)/%.o: $(SDIR)/%.c
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $^

objects.mk: configure
	./configure

runconf: configure
	./configure

re: fclean runconf all

.PHONY: all clean fclean re runconf

