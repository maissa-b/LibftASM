# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcat.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/08 19:18:49 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:29:29 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global		_ft_strcat

_ft_strcat:
	enter		0, 0				
	
	mov			rax, 0x00
	
	cmp			rdi, 0x00
	
	mov			r8, 0x00
	je			end

boucle_1:						
	cmp			byte [rdi], 0x00
	je			add
	
	inc			r8				
	inc			rdi
	jmp			boucle_1

add:							
	cmp			byte [rsi], 0x00
	je			add_null
	
	mov			al, byte [rsi]
	mov			byte [rdi], al
	
	inc			r8			
	inc			rdi
	inc			rsi
	
	jmp			add

add_null:	
	mov			byte [rdi], 0x00	

point_begining:				
	cmp			r8, 0x00
	je			end
	
	dec			r8
	dec			rdi
	
	jmp			point_begining

end:
	mov			rax, rdi
	leave
	ret
