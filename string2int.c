#include <stdio.h>
#include <string.h>

int str2int();

int main() {

	printf("str2int: %d \n", str2int("124582"));

	return 0;

}

int str2int(char* input) {

	int output = 0;
	int multiplier = 1;

	for (int i = 0; i < strlen(input); i++) {
		if (input[i] >= 48 && input[i] <= 57) {
			// DEBUG: printf(" = %d \n", strlen(input) - (i + 1));
			for (int j = 0; j < strlen(input) - (i + 1); j++) {
				multiplier *= 10;
			}
			output += (input[i] - 48) * multiplier;
			// DEBUG: printf("multiplier = %d \n", multiplier);
			multiplier = 1;
		} else {
			printf("Error! - NaN \n");
			output = 0;
			break;
		}
	}

	// DEBUG: printf("output = %d\r\n", output);

	return output;
}

//    convert string number to integer        "5" + "1" =  "51"
//     '1' -> 49 - 48   ==> 1       - '0', - 48
//     '4' -> 52 - 48  ===> 4
