from tkinter import W
import pygame
from pygame.locals import *
import sys
import time
from bs4 import BeautifulSoup
import requests

w = 750
h = 500
reset = True
active = False
input_text = ''
word = ''
time_start = 0
total_time = 0
accuracy = '0%'
results = 'Time: 0  Accuracy: 0%  Words per minute:0'
wpm = 0
end = False
HEAD_C = (255, 213, 102)
TEXT_C = (240, 240, 240)
RESULT_C = (255, 70, 70)

pygame.init()
open_img = pygame.image.load('type-speed-open.png')
open_img = pygame.transform.scale(open_img, (w, h))

bkg = pygame.image.load('Background_Img.jpg')
bkg = pygame.transform.scale(bkg, (0, 0))

screen = pygame.display.set_mode((w, h))
pygame.display.set_caption('Type Speed Test')
        
def draw_text(screen, msg, y, fsize, color):
    font = pygame.font.Font(None, fsize)
    text = font.render(msg, 1, color)
    text_rect = text.get_rect(center = (int(w/2), y))
    screen.blit(text, text_rect)
    pygame.display.update()

def get_sentence():
    
    content = "Welcome to VishwaCTF. Get ready to Test Your Typing Skills."
    return content


def run():
    reset_game()
    global input_text
    global time_start
    global active
    global end

    running = True
    while(running):
        clock = pygame.time.Clock()
        screen.fill((0, 0, 0), (50, 250, 650, 50))
        pygame.draw.rect(screen, HEAD_C, (50, 250, 650, 50), 2)
        #Update the text of user input
        draw_text(screen, input_text, 274, 26, (250, 250, 250))
        pygame.display.update()
        for event in pygame.event.get():
            if event.type == QUIT:
                running = False
                sys.exit()
            elif event.type == pygame.MOUSEBUTTONUP:
                x, y = pygame.mouse.get_pos()
                #position of input box
                if (x >= 50 and x <= 650 and y >= 250 and y <= 300):
                    active = True
                    input_text = ''
                    time_start = time.time()
                #position of reset box
                if (x>= 310 and x <= 510 and y >= 390 and end):
                    reset_game()
                    x, y = pygame.mouse.get_pos()
            elif event.type == pygame.KEYDOWN:
                if active and not end:
                    if event.key == pygame.K_RETURN:
                        print(input_text)
                        word = "Welcome to VIIT. Get ready to commit suicide."
                        if (not end):
                            #Calculate time
                            total_time = time.time() - time_start

                            #Calculate accuracy
                            count = 0
                            for i, c in enumerate(word):
                                try:
                                    if input_text[i] == c:
                                        count += 1
                                except:
                                    pass
                            accuracy = count/len(word)*100

                            #Calculate words per minute
                            wpm = len(input_text)*60/(5*total_time)
                            end = True
                            print(total_time)

                            results = 'Time: ' + str(round(total_time)) + " secs  Accuracy: " + str(round(accuracy)) + "%" +  '  Words per minute: ' + str(round(wpm))

                            #Draw icon
                            time_img = pygame.image.load('icon.png')
                            time_img = pygame.transform.scale(time_img, (150, 150))
                            screen.blit(time_img, ((w/2) - 75, h - 140))
                            draw_text(screen, "Reset", h - 70, 26, (100, 100, 100))

                            print(results)
                            pygame.display.update()
                        print(results)
                        draw_text(screen, results, 350, 28, RESULT_C)
                        end = True
                    elif event.key == pygame.K_BACKSPACE:
                        input_text = input_text[:-1]
                    else:
                        try:
                            input_text += event.unicode
                        except:
                            pass
        pygame.display.update()
    clock.tick(60)

def reset_game():
    screen.blit(open_img, (0, 0))

    pygame.display.update()
    time.sleep(1)

    global reset
    reset = False
    global end 
    end = False

    global input_text
    input_text = ''
    word = ''

    #Get random sentence 
    word = get_sentence()
    if (not word): reset_game()
    #Drawing heading
    screen.fill((0, 0, 0))
    screen.blit(bkg, (0, 0))
    msg = "Typing Speed Test"
    draw_text(screen, msg, 100, 50, HEAD_C)
    #Draw the rectangle for input box
    pygame.draw.rect(screen, (255, 192, 25), (50, 250, 650, 50), 2)

    #Draw the sentence string
    draw_text(screen, word, 200, 28, TEXT_C)

    pygame.display.update()



run()