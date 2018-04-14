/* This is the basic component. */
/* state */
type state = {count: int};

/* actions */
type action =
  | Increment
  | Decrement;

/* Your familiar handleClick from ReactJS. This mandatorily takes the payload,
   then the `self` record, which contains state (none here), `handle`, `reduce`
   and other utilities */
let handleClick = (_event, _self) => Js.log("clicked!");

let component = ReasonReact.reducerComponent("Page");

/* `make` is the function that mandatorily takes `children` (if you want to use
   `JSX). `message` is a named argument, which simulates ReactJS props. Usage:

   `<Page message="hello" />`

   Which desugars to

   `ReasonReact.element(Page.make(~message="hello", [||]))` */
let make = (~message, _children) => {
  ...component,
  initialState: () => {count: 0},
  reducer: (action, state) =>
    switch action {
    | Increment => ReasonReact.Update({count: state.count + 1})
    | Decrement => ReasonReact.Update({count: state.count - 1})
    },
  render: ({state, send}) =>
    <div>
      (ReasonReact.stringToElement(string_of_int(state.count)))
      <button onClick=((_e) => send(Increment))>
        (ReasonReact.stringToElement("Increment"))
      </button>
      <button onClick=((_e) => send(Decrement))>
        (ReasonReact.stringToElement("Decrement"))
      </button>
    </div>
};