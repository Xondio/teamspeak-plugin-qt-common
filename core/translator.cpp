#include "core/translator.h"

#include <QtCore/QString>
#include "core/ts_helpers_qt.h"
#include "core/ts_logging_qt.h"

Translator::Translator(QObject* parent, QString prefix)
	: QTranslator(parent)
	, kPrefix(prefix)
{}

bool Translator::update()
{
    const auto kLang = TSHelpers::GetLanguage();
    if (kLang.isEmpty())
        return false;

    const auto kIsTranslate = load(QStringLiteral(":/locales/") + kPrefix + "_" + kLang);
    if (!kIsTranslate)
        TSLogging::Log("No translation available.");

    return kIsTranslate;
}
