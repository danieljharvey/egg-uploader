/* This is the basic component. */
type state = {ctx: ref(option(Canvas.ctx))};

type action =
  | Nope;

external refToCanvas : Dom.element => Canvas.canvasElement = "%identity";

let refToContext = canv =>
  switch (Js.Nullable.toOption(canv)) {
  | Some(canv) => Some(Canvas.getContext(refToCanvas(canv)))
  | None => None
  };

let setCtxRef = (r, {ReasonReact.state}) => state.ctx := refToContext(r);

/* wondering about Js.Nullable.to_opt? See the note below */
let component = ReasonReact.reducerComponent("CanvasComponent");

/* Your familiar handleClick from ReactJS. This mandatorily takes the payload,
   then the `self` record, which contains state (none here), `handle`, `reduce`
   and other utilities */
/* `make` is the function that mandatorily takes `children` (if you want to use
   `JSX). `message` is a named argument, which simulates ReactJS props. Usage:

   `<Page message="hello" />`

   Which desugars to

   `ReasonReact.element(Page.make(~message="hello", [||]))` */
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
  didUpdate: self => Js.log2("DID UPDATE", self),
};