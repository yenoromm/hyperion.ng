#include "commandline/Option.h"
#include "commandline/Parser.h"

using namespace commandline;

Option::Option(const QString &name, const QString &description, const QString &valueName, const QString &defaultValue)
	: QCommandLineOption(name, description, valueName, defaultValue)
{}

Option::Option(const QStringList &names, const QString &description, const QString &valueName, const QString &defaultValue)
	: QCommandLineOption(names, description, valueName, defaultValue)
{}


bool Option::validate(Parser & parser, QString &value)
{
	/* By default everything is accepted */
	return true;
}

Option::Option(const QCommandLineOption &other)
	: QCommandLineOption(other)
{}

QString Option::value(Parser &parser)
{
	return parser.value(*this);
}

QString Option::name()
{
	return this->names().last();
}

QString Option::getError()
{
	return this->_error;
}

const char* Option::getCString(Parser &parser)
{
	return value(parser).toLocal8Bit().constData();
}
