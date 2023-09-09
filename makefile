CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = src
OBJDIR = obj
LIBDIR = lib
FT_PRINTF_PATH = ./ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_PATH)/libftprintf.a

CLIENT_SRC = $(SRCDIR)/client.c $(SRCDIR)/ft_atoi_m.c
SERVER_SRC = $(SRCDIR)/server.c

CLIENT_BONUS_SRC = $(SRCDIR)/client_bonus.c $(SRCDIR)/ft_atoi_m.c
SERVER_BONUS_SRC = $(SRCDIR)/server_bonus.c

CLIENT_OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(CLIENT_SRC))
SERVER_OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SERVER_SRC))

CLIENT_BONUS_OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(CLIENT_BONUS_SRC))
SERVER_BONUS_OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SERVER_BONUS_SRC))

CLIENT = client
SERVER = server

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus


all: $(CLIENT) $(SERVER) $(FT_PRINTF_LIB)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS) $(FT_PRINTF_LIB)

$(FT_PRINTF_LIB):	
	$(MAKE) -C $(FT_PRINTF_PATH)

$(CLIENT): $(CLIENT_OBJ) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $@ $^

$(SERVER): $(SERVER_OBJ) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $@ $^

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJ) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $@ $^

$(SERVER_BONUS): $(SERVER_BONUS_OBJ) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c 
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(CLIENT_BONUS_OBJ) $(SERVER_BONUS_OBJ)
	$(MAKE) -C $(FT_PRINTF_PATH) clean

fclean: clean
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	$(MAKE) -C $(FT_PRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re bonus