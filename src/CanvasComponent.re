open ReactTemplate.Canvas;

/* This is the basic component. */
type state = {ctx: ref(option(ctx))};

type action =
  | Nope;

type size = {
  width: float,
  height: float,
};

external refToCanvas : Dom.element => canvasElement = "%identity";

let refToContext = canv =>
  switch (Js.Nullable.toOption(canv)) {
  | Some(canv) => Some(getContext(refToCanvas(canv)))
  | None => None
  };

let setCtxRef = (r, {ReasonReact.state}) => state.ctx := refToContext(r);

/* wondering about Js.Nullable.to_opt? See the note below */
let component = ReasonReact.reducerComponent("CanvasComponent");

let getCanvasSize = (canvasElement: canvasElement) : size => {
  width: CanvasElement.width(canvasElement),
  height: CanvasElement.width(canvasElement),
};

let clearCanvas = (ctx: ctx) => {
  let size = getCanvasSize(Ctx.canvas(ctx));
  Js.log(size);
  Ctx.clearRect(ctx, 0.0, 0.0, size.width, size.height);
};

let drawBox = (ctx: ctx, box: CanvasTypes.box) => {
  let (startCoord, endCoord) = box.location;
  Ctx.setStrokeWidth(ctx, 3.0);
  Ctx.rect(
    ctx,
    startCoord.x,
    startCoord.y,
    endCoord.x - startCoord.x,
    endCoord.y - startCoord.y,
  );
  Ctx.stroke(ctx);
  ();
};

let drawBoxes = (ctx: ctx, boxes: list(CanvasTypes.box)) =>
  List.iter(drawBox(ctx), boxes);

let drawFeintBox =
    (ctx: ctx, startCoord: CanvasTypes.coord, endCoord: CanvasTypes.coord) => {
  Ctx.setStrokeWidth(ctx, 1.0);
  Ctx.rect(
    ctx,
    startCoord.x,
    startCoord.y,
    endCoord.x - startCoord.x,
    endCoord.y - startCoord.y,
  );
  Ctx.stroke(ctx);
};

let drawCurrentBox =
    (
      ctx: ctx,
      startCoord: option(CanvasTypes.coord),
      endCoord: option(CanvasTypes.coord),
    ) =>
  switch (startCoord) {
  | Some(start) =>
    switch (endCoord) {
    | Some(ending) => drawFeintBox(ctx, start, ending)
    | _ => ()
    }
  | _ => ()
  };

let updateCanvas = (ctx: ctx, state: CanvasTypes.state) => {
  clearCanvas(ctx);
  drawBoxes(ctx, state.boxes);
  drawCurrentBox(ctx, state.startCoord, state.endCoord);
  ();
};

let make =
    (
      ~reducerInterface:
         PipeTypes.reducerInterface(CanvasTypes.action, CanvasTypes.state),
      _children,
    ) => {
  ...component,
  initialState: () => {ctx: ref(None)},
  reducer: (action: action, state: state) =>
    switch (action) {
    | _ => ReasonReact.Update(state)
    },
  render: self =>
    <div>
      <canvas
        ref=(self.handle(setCtxRef))
        onMouseDown=(
          _event =>
            reducerInterface.send(
              CanvasTypes.MouseDown(
                ReactEventRe.Mouse.clientX(_event),
                ReactEventRe.Mouse.clientY(_event),
              ),
            )
        )
        onMouseMove=(
          _event =>
            reducerInterface.send(
              CanvasTypes.MouseMove(
                ReactEventRe.Mouse.clientX(_event),
                ReactEventRe.Mouse.clientY(_event),
              ),
            )
        )
        onMouseUp=(
          _event =>
            reducerInterface.send(
              CanvasTypes.MouseUp(
                ReactEventRe.Mouse.clientX(_event),
                ReactEventRe.Mouse.clientY(_event),
              ),
            )
        )
      />
      <BoxList boxes=reducerInterface.state.boxes />
    </div>,
  didUpdate: ({oldSelf, newSelf}) =>
    switch (newSelf.state.ctx^) {
    | Some(ctx) => updateCanvas(ctx, reducerInterface.state)
    | _ => ()
    },
};