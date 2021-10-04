# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 16:08:41 by aldubar           #+#    #+#              #
#    Updated: 2021/10/04 17:11:46 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM		ubuntu:latest

RUN			apt update && apt install -y make clang gcc xorg libxext-dev zlib1g-dev

WORKDIR		/.github/checker

ENTRYPOINT	[ "make" ]
