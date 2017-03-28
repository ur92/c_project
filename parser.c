#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "def.h"
#include "row.h"
#include "parser.h"

int segmentize_line(char segments[SEGMENTS_MAX][LINE_MAX], char *line){
    // char segments[SEGMENTS_MAX][LINE_MAX];
    int segment = 0;
    int i = 0, j = 0;
    int length = strlen(line);
    bool is_segment = false;
    bool with_label = false;
    
    //trim spaces
    while(isspace(*line[i]) && i<length)
        i++;
    
    // empty line
    if(i==length)
        return 0;

    // coment line    
    if(*line[i] == COMMENT_CHAR)
        return 0;
    
    // first segment (label or command)
    while(!isspace(*line[i]) && i<length){
        segments[segment][j] = *line[i];
        i++;
        j++;
    }
    segments[segment][j] = '\0';
    if(strlen(segments[segment]) > 0){
        if(strchr(segments[segment], LABEL_CHAR)){
            with_label = true;
        }
    }
    
    //trim spaces
    while(isspace(*line[i]) && i<length)
        i++;
    
    if(with_label){
        // second segment (command)
        j = 0;
        segment++;
        while(!isspace(*line[i]) && i<length){
            segments[segment][j] = *line[i];
            i++;
            j++;
        }
    }
    
    //trim spaces
    while(isspace(*line[i]) && i<length)
        i++;
    
    // second segment (operands)
    j = 0;
    segment++;
    while(i<length){
        if(!isspace(*line[i]){
            segments[segment][j] = *line[i];
            j++;
        }
        i++;
    }
    
    return segment;
}

Row parse_line(char *line){
    bool with_label = false;
    char segments[SEGMENTS_MAX][LINE_MAX];
    
    int number_of_segments = segmentize_line(line, segments);
    
    if(strlen(segments[0]) > 0){
        if(strchr(segments[0], LABEL_CHAR)){
            with_label = true;
        }
    }
    
    
    Row row = create_row(0,
                        with_label,
                        false,
                        false,
                        false,
                        IMMIDIATE,
                        "asd",
                        IMMIDIATE,
                        "asdd",
                        "comm",
                        "label",
                        0);
    
}

