/*
istream& operator >> (istream& inputStream, Percent& aPercent)
{
        char percentSign;
        inputStream >> aPercent.value;
        inputStream >> percentSign;
        return inputStream;
}

ostream& operator <<(ostream& outputStream, const Percent& aPercent){
    outputStream << aPercent.value << '%';
    return outputStream;
}

*/