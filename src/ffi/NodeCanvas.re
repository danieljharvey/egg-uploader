/* stolen from https://github.com/reasonml-community/reason-maze/blob/0fff27e2314a25a4d6b1bacb6e7075a069b90dca/src/FFI/NodeCanvas.re thanks guys! */
type canvas;

[@bs.new] [@bs.module] external canvas : (int, int) => canvas = "canvas";

[@bs.send] external getContext : (canvas, string) => Canvas.ctx = "";

type pngBuffer;

[@bs.send] external toBuffer : canvas => pngBuffer = "";

[@bs.module "fs"]
external saveAs : (string, pngBuffer) => unit = "writeFileSync";