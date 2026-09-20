#include "CommandFactory.h"
#include "Command.h"
#include "EchoCommand.h"
#include "DateCommand.h"
#include "TouchCommand.h"
#include "WcCommand.h"
#include "TimeCommand.h"
#include "PromptCommand.h"
#include "TruncateCommand.h"
#include "rmCommand.h"
#include "trCommand.h"
#include "HeadCommand.h"
#include "BatchCommand.h"
#include "string"
#include "string"

Command* CommandFactory::create(const std::string& name,
    const std::string& opt,
    const std::string& text,
    const std::string& arg) {

    if (name == "echo")
        return new EchoCommand(text);

    if (name == "date")
        return new DateCommand();

    if (name == "touch")
        return new TouchCommand(arg);

    if (name == "wc")
        return new WcCommand(opt, text);

    if (name == "time") {
        return new TimeCommand();
    }
    if (name == "prompt") {
        return new PromptCommand(arg);
    }
    if (name == "truncate") {
        return new TruncateCommand(arg);
    }
    if (name == "rm") {
        return new rmCommand(arg);
    }
    if (name == "tr") {
        return new TrCommand(opt,arg,text);
    }
    if (name == "head") {
        return new HeadCommand(opt,text);
    }
    if (name == "batch") {
        return new BatchCommand(arg);
    }

    return nullptr;
};
