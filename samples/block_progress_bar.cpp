#include <chrono>
#include <indicators/block_progress_bar.hpp>
#include <indicators/cursor_control.hpp>
#include <thread>

int main() {

  // Hide cursor
  indicators::show_console_cursor(false);

  indicators::BlockProgressBar bar{
      indicators::option::BarWidth{80},
      indicators::option::FontStyles{
          std::vector<indicators::FontStyle>{indicators::FontStyle::bold}}};

  // Update bar state
  size_t progress = 0;
  while (true) {
    bar.set_progress(progress);
    progress++;
    if (bar.is_completed())
      break;
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }

  // Show cursor
  indicators::show_console_cursor(true);

  return 0;
}
