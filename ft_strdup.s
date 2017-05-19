# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/16 19:32:36 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:33:07 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
    global          _ft_strdup
    extern          _ft_strlen
    extern          _ft_memcpy
    extern          _malloc

_ft_strdup:
    cmp             rdi, 0x00
    je              end
    
    mov             rbx, rdi
    
    call            _ft_strlen
    mov             rdi, rax
    inc             rdi
    push            rdi
    
    call            _malloc
    cmp             rax, 0
    je              end

    mov             rdi, rax
    mov             rsi, rbx
    pop             rdx

    call            _ft_memcpy

end:
    ret
