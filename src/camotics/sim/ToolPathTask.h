/******************************************************************************\

  CAMotics is an Open-Source simulation and CAM software.
  Copyright (C) 2011-2019 Joseph Coffland <joseph@cauldrondevelopment.com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

\******************************************************************************/

#pragma once


#include <camotics/Task.h>

#include <gcode/Units.h>
#include <gcode/ToolPath.h>
#include <gcode/ToolTable.h>
#include <gcode/ControllerImpl.h>
#include <gcode/machine/MachinePipeline.h>

#include <string>
#include <vector>
#include <sstream>


namespace cb {
  class Subprocess;
  class Thread;
  class InputSource;
}

namespace GCode {
  class Controller;
  class MachineInterface;
}

#ifdef HAVE_V8
namespace tplang {class TPLContext;}
#endif

namespace CAMotics {
  namespace Project {class Project;}

  class ToolPathTask : public Task {
    GCode::ToolTable tools;
    GCode::Units units;
    std::vector<std::string> files;
    std::string simJSON;

    GCode::MachinePipeline machine;
    GCode::ControllerImpl controller;

    unsigned errors = 0;
    cb::SmartPointer<GCode::ToolPath> path;
    std::ostringstream gcode;

    cb::SmartPointer<cb::Subprocess> proc;
    cb::SmartPointer<cb::Thread> logCopier;

#ifdef HAVE_V8
    cb::SmartPointer<tplang::TPLContext> tplCtx;
#endif

    public:
    ToolPathTask(const Project::Project &project);
    ~ToolPathTask();

    unsigned getErrorCount() const {return errors;}
    const cb::SmartPointer<GCode::ToolPath> &getPath() const {return path;}
    std::string getGCode() const {return gcode.str();}

    void interpGCode(const cb::InputSource &src);

    void runTPL(const std::string &filename);
    void runTPLInProcess(const std::string &filename);
    void runGCode(const std::string &filename);

    // From Task
    void run();
    void interrupt();
  };
}
