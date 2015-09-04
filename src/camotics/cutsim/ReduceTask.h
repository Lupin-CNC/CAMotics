/******************************************************************************\

    CAMotics is an Open-Source CAM software.
    Copyright (C) 2011-2015 Joseph Coffland <joseph@cauldrondevelopment.com>

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

#ifndef CAMOTICS_REDUCE_TASK_H
#define CAMOTICS_REDUCE_TASK_H

#include <camotics/Task.h>

#include <cbang/SmartPointer.h>


namespace CAMotics {
  class Surface;

  class ReduceTask : public Task {
    cb::SmartPointer<Surface> surface;

  public:
    ReduceTask(const Surface &surface);

    const cb::SmartPointer<Surface> &getSurface() const {return surface;}

    // From Task
    void run();
  };
}

#endif // CAMOTICS_REDUCE_TASK_H
