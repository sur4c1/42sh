NAME		= 42sh

SDIR		= srcs
ODIR		= objs
IDIR		= incs
LDIR		= libs

CC			= cc
RM			= rm -rf
MKDIR		= mkdir -p
CFLAGS		= -Wall -Wextra -Werror
CFLAGS		+= -I$(IDIR) -I$(LDIR)/libft
LDFLAGS		= -L$(LDIR)/libft -lft

LIBS		= libs/libft/libft.a
OBJS = $(addprefix $(ODIR)/, $(addsuffix .o, $(SRCS)))

.DEFAULT_GOAL := all

include objects.mk

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(ODIR)

fclean: clean
	$(RM) $(NAME) objects.mk
	$(MAKE) -C $(LDIR)/libft

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
