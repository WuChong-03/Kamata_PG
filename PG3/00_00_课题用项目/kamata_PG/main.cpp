#include <stdio.h>
#include <string.h>

#include <list>

void PrintStations(const char* year, const std::list<const char*>& stations) {
	printf("===== %s =====\n", year);

	int number = 1;
	for (std::list<const char*>::const_iterator itr = stations.begin(); itr != stations.end(); ++itr) {
		printf("%2d: %s\n", number, *itr);
		number++;
	}

	printf("\n");
}

void InsertBefore(std::list<const char*>& stations, const char* target, const char* station) {
	for (std::list<const char*>::iterator itr = stations.begin(); itr != stations.end(); ++itr) {
		if (strcmp(*itr, target) == 0) {
			stations.insert(itr, station);
			return;
		}
	}
}

int main() {
	std::list<const char*> stations1970 = {
		"Tokyo",       "Kanda",       "Akihabara", "Okachimachi", "Ueno",    "Uguisudani",
		"Nippori",     "Tabata",      "Komagome",  "Sugamo",      "Otsuka",  "Ikebukuro",
		"Mejiro",      "Takadanobaba", "Shin-Okubo", "Shinjuku",    "Yoyogi",  "Harajuku",
		"Shibuya",     "Ebisu",       "Meguro",    "Gotanda",     "Osaki",   "Shinagawa",
		"Tamachi",     "Hamamatsucho", "Shimbashi", "Yurakucho",
	};

	std::list<const char*> stations2019 = stations1970;
	InsertBefore(stations2019, "Tabata", "Nishi-Nippori");

	std::list<const char*> stations2022 = stations2019;
	InsertBefore(stations2022, "Tamachi", "Takanawa Gateway");

	PrintStations("1970", stations1970);
	PrintStations("2019", stations2019);
	PrintStations("2022", stations2022);

	return 0;
}
