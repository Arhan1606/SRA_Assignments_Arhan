#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sra_board.h"

void app_main()
{
    ESP_ERROR_CHECK(enable_bar_graph());
    // enable_bar_graph() turns on the gpio pins, if it succeeds it returns ESP_OK else it returns ESP_FAIL
    // If the argument of ESP_ERROR_CHECK() is not equal ESP_OK, then an error message is printed on the console, and abort() is called. 
        
    
    while(1) //Starting the while loop so that it can run infinite times
        { 

            ESP_ERROR_CHECK(set_bar_graph(0xAA)); //0xAA is the hexadecimal for even position led's
            // So using the function even led's are on
            vTaskDelay(500 / portTICK_PERIOD_MS); // delay of 500 ms

            ESP_ERROR_CHECK(set_bar_graph(0x55)); //0x55 is the hexadecimal for odd position led's
            // So using the function odd led's are on
            vTaskDelay(500/portTICK_PERIOD_MS); // delay of 500 ms


        }
}
