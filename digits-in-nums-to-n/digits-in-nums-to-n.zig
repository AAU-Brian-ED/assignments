const std = @import("std");
const stdout = std.io.getStdOut().writer();

fn ask_for_number() !u32 {
    const stdin = std.io.getStdIn().reader();

    var buf: [10]u8 = undefined;

    try stdout.print("A number please: ", .{});

    if (try stdin.readUntilDelimiterOrEof(buf[0..], '\n')) |user_input| {
        return std.fmt.parseInt(u32, user_input, 10);
    } else {
        return @as(u32, 0);
    }
}

pub fn main() !void {
  const n = try ask_for_number();
  const cifre = try ask_for_number();

  var found:u32 = 0;
  var i = n;
  while (i>0) {
    var t=i;
    while (t!=0) {
      if (t%10 == cifre) {
        found+=1;
        break;
      }
      t/=10;
    }
    i-=1;
  }

  try stdout.print("{}\n", .{found});
}

