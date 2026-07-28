NAME		= 42sh

SDIR		= srcs
ODIR		= objs
IDIR		= incs
LDIR		= libs

CC			= cc
RM			= rm -rf
MKDIR		= mkdir -p
CFLAGS		= -Wall -Wextra -Werror
CFLAGS		+= -I$(IDIR) -I$(LDIR)/libft/incs
LDFLAGS		= -L$(LDIR)/libft -lft

LIBS		= libs/libft/libft.a

.DEFAULT_GOAL := all

objects.mk: configure
	./configure

include objects.mk

all: $(NAME)

$(NAME): $(ODIR) $(OBJS) $(LIBS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

$(ODIR):
	$(MKDIR) $(ODIR)

clean:
	$(RM) $(ODIR)

fclean: clean
	$(RM) $(NAME) objects.mk

$(LDIR)/libft/libft.a:
	$(MAKE) -C $(LDIR)/libft

re: fclean all

.PHONY: all clean fclean re
