#include <QStringList>
#include "versionfunction.h"
#include "vectorvalue.h"
#include "numbervalue.h"
#include "textvalue.h"

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
VersionFunction::VersionFunction() : Function("version")
{
	QString v=TOSTRING(RAPCAD_VERSION);
	QStringList parts=v.split(".");
	int major=parts.at(0).toInt();
	int minor=parts.at(1).toInt();
	QString build=parts.at(2);
	version.append(new NumberValue(major));
	version.append(new NumberValue(minor));
	if(build=="git") {
		version.append(new TextValue(build));
		QString revision=parts.at(3);
		version.append(new TextValue(revision));
	} else {
		version.append(new NumberValue(build.toInt()));
	}
}

Value* VersionFunction::evaluate(Context*)
{
	return new VectorValue(version);
}
