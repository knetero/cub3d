# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/09 13:07:13 by abazerou          #+#    #+#              #
#    Updated: 2023/11/16 18:20:59 by abazerou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_bzero.c \
			ft_memset.c ft_strrchr.c ft_isprint.c ft_memcmp.c ft_memchr.c ft_memcpy.c \
			ft_atoi.c ft_toupper.c ft_tolower.c ft_strnstr.c ft_calloc.c ft_memmove.c ft_strlcat.c ft_substr.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

SRCS_B	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			
NAME	=	libft.a 

HEADER	=	libft.h

CFLAGS	=	-Wall -Wextra -Werror

OBJ		=	$(SRCS:.c=.o)
OBJSB	=	$(SRCS_B:.c=.o)

all : $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

$(NAME) : $(OBJ) 
	ar -rc $(NAME) $(OBJ)

clean :
	rm -f $(OBJ) $(OBJB)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : all $(OBJB)
	ar -rc $(NAME) $(OBJB)