#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cctype>
# include <cstdlib>
# include <algorithm>

struct s_TransactionValues
{
	float		volume;
	float		exchangeRate;
	float		total;
	bool		badDate;
	bool		badVolume;
	std::string	priceReferenceDate;
};

typedef std::map<int, float>::iterator BTCpriceHistoryIt;
typedef std::pair<std::string, s_TransactionValues> closedPositionsPair;

std::ostream& 	operator<<(std::ostream& os,
	const std::pair<std::string, s_TransactionValues>& closedPositions);

void			ErrorMessage(const char* errorMessage, int errorCode);
void			ReadDataFile(std::map<int, float>& BitcoinPriceHistory);
void			ReadClosedPositionsFile
	(std::map<int, float> BitcoinPriceHistory, std::ifstream& infile);
void			parseDate(std::string& date, bool& badDate);
float			parseVolume(std::string volume, bool& badVolume);
bool			bad_day(int year, int month, int day);
int				dateToValue(const std::string& date);
std::string		valueToDate(const int& dateValue);

#endif
